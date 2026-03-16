class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp, int m) {
        if (i==m) 
        {
            return 0;
        }
        if (dp[i][j]!=-1) 
        {
            return dp[i][j];
        }
        return dp[i][j]=triangle[i][j]+min(solve(triangle,i+1,j,dp,m),solve(triangle,i+1,j+1,dp, m));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(triangle,0,0,dp,m);
    }
};
