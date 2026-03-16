class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int cur=image[sr][sc];
        if (cur==color) 
        return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while (!q.empty()) 
        {
            int i= q.front().first;
            int j=q.front().second;
            q.pop();
            for (auto d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni>=0 && nj>=0 && ni<n && nj<m && image[ni][nj] == cur) {
                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }
        return image;
    }
};