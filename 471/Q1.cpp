class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int x: nums) mp[x]++;

        int ans = 0;
        
        for(auto ele: mp){
            if(ele.second %k == 0) ans += ele.first* ele.second;
        }

        return ans;
    }
};