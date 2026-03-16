class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp,
              vector<vector<int>>& minRow, vector<vector<int>>& secondMinRow,
              vector<vector<int>>& idxRow) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        if (minRow[i + 1].empty()) {
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
            for (int k = 0; k < n; k++) {
                int val =
                    solve(i + 1, k, grid, dp, minRow, secondMinRow, idxRow);
                if (val < min1) {
                    min2 = min1;
                    min1 = val;
                    idx1 = k;
                } 
                else if (val < min2) {
                    min2 = val;
                }
            }
            minRow[i + 1] = {min1};
            secondMinRow[i + 1] = {min2};
            idxRow[i + 1] = {idx1};
        }
        int min1 = minRow[i + 1][0], min2 = secondMinRow[i + 1][0],
            idx1 = idxRow[i + 1][0];
        int bestNext = (j == idx1) ? min2 : min1;
        return dp[i][j] = grid[i][j] + bestNext;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> minRow(m), secondMinRow(m), idxRow(m);
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, solve(0, j, grid, dp, minRow, secondMinRow, idxRow));
        return ans;
    }
};