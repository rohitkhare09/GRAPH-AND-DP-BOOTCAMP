class Solution {
public:
bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, char ch, int parRow, int parCol){
        int m = grid.size(), n = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == ch)
            {
                if(vis[nrow][ncol] == 0)
                {
                    if(dfs(grid, vis, nrow, ncol, ch, row, col)) 
                    return true;
                }
                else if(nrow != parRow || ncol != parCol)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j])
                {
                    if(dfs(grid, vis, i, j, grid[i][j], -1, -1)) 
                    return true;
                }
            }
        }
        return false;
    }
};