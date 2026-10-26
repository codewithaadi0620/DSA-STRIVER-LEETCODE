class Solution {
public:
    long long dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum = grid[row][col];
        grid[row][col] = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                grid[newRow][newCol] > 0) {
                sum += dfs(newRow, newCol, grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long isIsland = dfs(i, j, grid);
                    if (isIsland % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};