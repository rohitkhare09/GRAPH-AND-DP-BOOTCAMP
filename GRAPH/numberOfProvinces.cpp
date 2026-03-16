class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                bfs(i, adj, vis);
            }
        }
        return components;
    }
};
