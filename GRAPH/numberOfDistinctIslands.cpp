class Solution {
private:
    void bfs(int row, int col, vector<vector<bool>>& vis,
             vector<vector<int>>& grid, vector<pair<int,int>>& shape) {
        vis[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();
        int row0 = row, col0 = col;  
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            shape.push_back({i - row0, j - col0});
            if (j+1 < m && grid[i][j+1] == 1 && !vis[i][j+1]) {
                vis[i][j+1] = true;
                q.push({i, j+1});
            }
            if (j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]) {
                vis[i][j-1] = true;
                q.push({i, j-1});
            }
            if (i+1 < n && grid[i+1][j] == 1 && !vis[i+1][j]) {
                vis[i+1][j] = true;
                q.push({i+1, j});
            }
            if (i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]) {
                vis[i-1][j] = true;
                q.push({i-1, j});
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int,int>>> distinctShapes;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == 1) {
                    vector<pair<int,int>> shape;
                    bfs(row, col, vis, grid, shape);
                    distinctShapes.insert(shape);
                }
            }
        }
        return distinctShapes.size();
    }
};
