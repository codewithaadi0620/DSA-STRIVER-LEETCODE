class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<bool> pairXor(2048, false);
        vector<bool> tripleXor(2048, false);

        // Compute all possible pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // Generate all possible triplet XORs
        for (int num : nums) {
            for (int x = 0; x < 2048; x++) {
                if (pairXor[x]) {
                    tripleXor[x ^ num] = true;
                }
            }
        }

        // Count distinct XOR values
        int count = 0;
        for (bool exists : tripleXor) {
            if (exists) count++;
        }

        return count;
    }
};