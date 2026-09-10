class Solution {
public:
    void rev(int i, int j, vector<char>& s) {
        if (j < i)
            return;
        swap(s[i], s[j]);
        rev(i + 1, j - 1, s);
    }
    void reverseString(vector<char>& s) { rev(0, s.size() - 1, s); }
};