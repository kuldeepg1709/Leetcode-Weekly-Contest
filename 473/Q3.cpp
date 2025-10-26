class Solution {
public:
    long long countStableSubarrays(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return 0;

        vector<long long> pre(n+1, 0);
        for (int i=0;i<n;i++) pre[i+1] = pre[i] + nums[i];

        long long ans = 0;
        map<pair<long long, long long>, int> mp;

        for (int r=2;r<n;r++){
            int l = r-2;
            mp[{nums[l], pre[l]}]++;

            long long val = nums[r];
            long long req = pre[r]- 2*val;

            if (mp.count({val, req})) ans += mp[{val, req}];
        }

        return ans;
    }
};
