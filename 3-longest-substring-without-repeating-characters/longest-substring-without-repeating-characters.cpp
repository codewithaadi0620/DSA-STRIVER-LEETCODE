class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxi = 0;
        unordered_set<char> st;
        while (r < s.size()) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxi = max(maxi, (int)st.size());
            r++;
        }
        return maxi;
    }
};