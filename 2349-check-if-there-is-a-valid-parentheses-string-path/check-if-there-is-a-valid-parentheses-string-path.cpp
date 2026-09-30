class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // A valid parentheses string must have an even length
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        
        // Impossible to start with a closing bracket or end with an opening bracket
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') {
            return false;
        }
        
        // visited[r][c][balance]
        int max_len = m + n - 1;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(max_len + 1, false)));
        
        return dfs(grid, 0, 0, 0, visited);
    }
    
private:
    bool dfs(vector<vector<char>>& grid, int r, int c, int balance, vector<vector<vector<bool>>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Update balance based on the current cell
        balance += (grid[r][c] == '(' ? 1 : -1);
        
        // Condition 1: Balance can never drop below zero
        if (balance < 0) return false;
        
        // Condition 2: Remaining steps must be enough to close the open brackets
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (balance > remaining_steps) return false;
        
        // If we reach the bottom-right corner, check if brackets are perfectly matched
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }
        
        // Return if this state has been visited
        if (visited[r][c][balance]) {
            return false;
        }
        
        // Mark current state as visited to avoid redundant calculations
        visited[r][c][balance] = true;
        
        // Explore right and down
        if (c + 1 < n && dfs(grid, r, c + 1, balance, visited)) {
            return true;
        }
        if (r + 1 < m && dfs(grid, r + 1, c, balance, visited)) {
            return true;
        }
        
        return false;
    }
};