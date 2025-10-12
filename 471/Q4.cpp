vector<long long> primes;

class Solution {
private:
    void dfs(long long &ans, int root, vector<vector<int>> &adj, int parent, unordered_map<long long, long long> &done, vector<long long>& sqrFree){
        long long val = sqrFree[root];
        
        if(done.count(val)) ans += done[val];

        done[val]++;
        
        for(int nxt: adj[root]){
            if(nxt != parent){
                dfs(ans, nxt, adj, root, done, sqrFree);
            }
        }
        
        if(done[val] > 1) done[val]--;
        else done.erase(val);
        
    }
    // sieve of eratosthenes for finding primes
    void generatePrimes(){
        vector<bool> arr(400, true);

        for(int i=2;i<400;i++){
            if(arr[i] == true){
                for(int j=2*i;j<400;j+=i) arr[j] = false;
            }
        }

        for(int p=2;p<400;p++) if(arr[p]) primes.push_back(p);
    }

    // function to reduce the number into square free or removing the primes with even power

    long long odd(int n){

        if(n < 2) return 1;

        long long ans = 1;

        for(int p: primes){
            int cnt = 0; // checking power of p in prime factorisation of n

            while(n%p == 0){
                cnt++;
                n = n/p;
            }

            if(cnt&1) ans*=p;
        }

        return ans*n; // n conatins the primes > 400 as they can only occur atmost once(because 400*400 = 1.6e5 > 1e5)
    }
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> adj(n);

        for(auto &e: edges){
            // undirected
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if(primes.size() == 0) generatePrimes(); // generate primes only once no need to generate for each testcase

        long long ans = 0;

        vector<long long> sqrFree; // square free node values

        for(int i=0;i<n;i++) sqrFree.push_back(odd(nums[i]));

        unordered_map<long long, long long> done;

        // keeping -1 parent for 0
        dfs(ans, 0, adj, -1, done, sqrFree);

        return ans;
    }
};