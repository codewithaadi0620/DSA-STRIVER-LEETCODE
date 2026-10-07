class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int ans = 0;
        map<char, int> mpp;
        int maxFreq = 0;

        while (r < s.size()) {

            mpp[s[r]]++;

            maxFreq = max(maxFreq, mpp[s[r]]);

            int len = r - l + 1;
            int change = len - maxFreq;

            while (change > k) {
                mpp[s[l]]--;
                l++;

                len = r - l + 1;
                change = len - maxFreq;
            }

            ans = max(ans, len);

            r++;
        }

        return ans;
    }
};