class Solution {
public:
    // bruteforce since n <= 1000
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(ok(mp)) ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
private:
    bool ok(unordered_map<char,int> &mp){
        int val = mp.begin()->second;
        for(auto ele: mp){
            if(ele.second != val) return false;
        }
        return true;
    }
};