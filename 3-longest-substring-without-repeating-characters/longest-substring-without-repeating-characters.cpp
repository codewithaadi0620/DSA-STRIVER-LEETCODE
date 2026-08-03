class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        vector<int> hash(256, -1);
        
        while (r < s.size()) {
   
            if (hash[s[r]] != -1) {
                l = max(l, hash[s[r]] + 1);
            }
            
            hash[s[r]] = r;              
            ans = max(ans, r - l + 1);   
            r++;                          
        }
        
        return ans;
    }
};