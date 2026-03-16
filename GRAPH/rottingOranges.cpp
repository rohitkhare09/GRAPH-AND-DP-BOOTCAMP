class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;  
        int fresh=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                if(grid[i][j]==2) 
                {
                    q.push({i, j}); 
                } 
                else if(grid[i][j]==1) 
                {
                    fresh++;
                }
            }
        }
        if (fresh==0) 
        {
            return 0;
        }
        int time=0;
        int dx[4]={0,0,1,-1};
        int dy[4] ={1,-1,0,0};
        while(!q.empty() && fresh>0) 
        {
            int size=q.size();
            bool isRot=false;
            for(int i=0;i<size;i++) 
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++) 
                {
                    int nx=x+dx[k];
                    int ny= y+dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) 
                    {
                        grid[nx][ny]=2;   
                        fresh--;            
                        q.push({nx,ny});
                        isRot=true;
                    }
                }
            }
            if(isRot) 
            {
                time++;
            }
        }
        if(fresh==0)
        {
            return time;
        }
        else
        {
            return -1;
        }
    }
};