class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m > n) return -1;
        
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int h_idx = 0;
        int n_idx = 0;
        
        while (h_idx < n) {
            if (haystack[h_idx] == needle[n_idx]) {
                h_idx++;
                n_idx++;
            }
            
            if (n_idx == m) {
                return h_idx - n_idx;
            } else if (h_idx < n && haystack[h_idx] != needle[n_idx]) {
                if (n_idx != 0) {
                    n_idx = lps[n_idx - 1];
                } else {
                    h_idx++;
                }
            }
        }
        
        return -1;
    }
};