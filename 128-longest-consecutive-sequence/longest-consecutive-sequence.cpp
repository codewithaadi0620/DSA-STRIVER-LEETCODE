class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;

        for (int x : nums) {
            hashSet.insert(x);
        }

        int longest = 0;

        for (int x : hashSet) {
            // x is the beginning of a sequence
            if (hashSet.find(x - 1) == hashSet.end()) {
                int count = 1;

                while (hashSet.find(x + 1) != hashSet.end()) {
                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};