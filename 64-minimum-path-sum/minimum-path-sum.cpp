class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
        if (i >= n || j >= m) return INT_MAX;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        return dp[i][j] = grid[i][j] +
               min(solve(i, j + 1, grid, n, m, dp),
                   solve(i + 1, j, grid, n, m, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        return solve(0, 0, grid, n, m, dp);
    }
};