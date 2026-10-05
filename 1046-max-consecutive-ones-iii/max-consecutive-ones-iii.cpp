class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int maxi = 0;
        int len = 0;
        int zeros = 0;
        while (r < nums.size()) {
            if (nums[r] == 0)
                zeros++;
            while (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            len = r - l + 1;
            maxi = max(len, maxi);

            r++;
        }
        return maxi;
    }
};