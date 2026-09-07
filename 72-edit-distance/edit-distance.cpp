class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &word1, string &word2) {
        if (i == word1.length()) {
            return word2.length() - j;
        }
        if (j == word2.length()) {
            return word1.length() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);
        }

        int insert = solve(i, j + 1, word1, word2);
        int remove = solve(i + 1, j, word1, word2);

        int replace = solve(i + 1, j + 1, word1, word2);

        return dp[i][j] = 1 + min({insert, remove, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        dp.assign(n, vector<int>(m, -1));

        return solve(0, 0, word1, word2);
    }
};