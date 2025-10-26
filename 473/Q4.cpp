class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        // Counting all subarrays with mod k = 0
        unordered_map<long long, long long> mp;
        long long sum = 0, n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum%k]++;
            ans += (mp[sum%k]-1);

            if(sum%k == 0) ans++; // this means [0---i]%k == 0
        }

        // excluding repeated ones

        for(int i=0;i<n;i++){
            int j = i+1;            
            while(j < n && nums[j] == nums[i]) j++;

            long long curr = 0;

            for(int l=i;l<j;l++){
                curr += nums[l];

                if(curr%k == 0) ans -= (j-l-1);
            }

            i = j-1;
        }
                
        return ans;
    }
};
