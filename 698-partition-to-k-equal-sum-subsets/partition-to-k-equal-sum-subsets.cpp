class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int summ= accumulate(nums.begin(), nums.end(), 0);

     
        if (summ % k != 0)
            return false;

        int rSum = summ / k;

        
        vector<bool> dp(1 << n, false);
        dp[0] = true;

        vector<int> sum(1 << n, 0);

        for (int mask = 1; mask < (1 << n); mask++) {
            int bit = __builtin_ctz(mask & -mask);
            int prev = mask ^ (1 << bit);
            sum[mask] = sum[prev] + nums[bit];
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            if (!dp[mask])
                continue;

            int currSum = sum[mask] % rSum;

            for (int i = 0; i < n; i++) {
               
                if (mask & (1 << i))
                    continue;

          
                if (currSum + nums[i] > rSum)
                    continue;

                int newMask = mask | (1 << i);
                dp[newMask] = true;
            }
        }

        return dp[(1 << n) - 1];
    }
};