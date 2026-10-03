class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int i = 0, j = 0;

        set<char> valid;

        while (j < s.size()) {

            // Remove characters until s[j] is unique
            while (valid.find(s[j]) != valid.end()) {
                valid.erase(s[i]);
                i++;
            }

            // Add current character
            valid.insert(s[j]);

            // Update maximum window length
            maxLength = max(maxLength, (int)valid.size());

            // Expand window
            j++;
        }

        return maxLength;
    }
};