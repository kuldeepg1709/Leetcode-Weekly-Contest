class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        ans = max(ans, one(s, 'a'));
        ans = max(ans, one(s, 'b'));
        ans = max(ans, one(s, 'c'));

        ans = max(ans, two(s, 'a', 'b'));
        ans = max(ans, two(s, 'a', 'c'));
        ans = max(ans, two(s, 'b', 'c'));

        ans = max(ans, three(s));

        return ans;
    }

private:
    // cheking valid string with just 1 char
    int one(string s, char c){
        int len = 0, ans = 0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == c) len++;
            else len = 0; // reset len to 0
            ans = max(ans, len); // we need to check the answer at every position
        }
        
        return ans;
    }

    // cheking valid string charactor conating c1 and c2 with equal frequency
    int two(string s, char c1, char c2){
        int x = 0, y = 0; // c1 count and c2 count
        int ans = 0, n = s.size();

        // to check if we already visited index i from where xi,yi and xj,yj form a valid required substring we can use a map with difference of xi and yi

        map<int,int> mp;

        for(int i=0;i<n;i++){
            if(s[i] == c1) x++;
            else if(s[i] == c2) y++;
            else x = 0, y = 0, mp.clear(); // case where the 3rd char occurs and we need reset every thing

            // case when x= y and x != y
            if(x == y) ans = max(ans, 2*x);
            else{
                if(mp.count(x-y)) ans = max(ans, i - mp[x-y]);
            }

            if(!mp.count(x-y)) mp[x-y] = i; // updating map only if we have not visited difference
        }

        return ans;
    }

    // checking valid subtrings with equal no of a,b,c all
    int three(string s){
        int x = 0, y = 0, z = 0;

        int n = s.size(), ans = 0;

        map<pair<int,int>, int> mp;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') x++;
            else  if(s[i] == 'b') y++;
            else z++;

            pair<int,int> ele = {x-y, y-z};

            if(x == y && y == z) ans = max(ans, 3*x);
            else{
                // checking if all chars occur atleast once
                if(x > 0 && y > 0 && z > 0 && mp.count(ele)){
                    ans = max(ans, i - mp[ele]);
                }
            }

            if(!mp.count(ele)) mp[ele] = i; // updating map only if we have not visited difference
        }
        return ans;
    }
};