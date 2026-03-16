class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& d, vector<vector<int>>& dp) {
        int m = d.size();
        int n = d[0].size();
        if (i >= m || j >= n)
            return 1e9;
        if (i == m - 1 && j == n - 1)
            return max(1, 1 - d[i][j]);
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = solve(i + 1, j, d, dp);
        int right = solve(i, j + 1, d, dp);
        int need = min(down, right) - d[i][j];
        return dp[i][j] = max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dungeon, dp);
    }
};