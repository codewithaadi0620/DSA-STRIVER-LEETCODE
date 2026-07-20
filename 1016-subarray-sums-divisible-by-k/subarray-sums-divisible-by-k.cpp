class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0;
        int cnt = 0;

        for (int num : nums) {
            preSum += num;

            int remainder = preSum % k;

            // Handle negative remainder
            if (remainder < 0)
                remainder += k;

            cnt += mpp[remainder];
            mpp[remainder]++;
        }

        return cnt;
    }
};