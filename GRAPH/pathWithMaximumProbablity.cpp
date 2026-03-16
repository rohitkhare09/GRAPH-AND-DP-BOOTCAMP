class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i=0;i<edges.size();i++) 
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double>best(n,0.0);
        best[start]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        while (!pq.empty()) 
        {
            auto [prob,u]=pq.top();
            pq.pop();
            if (u==end) 
            return prob;
            if (prob<best[u]) 
            continue;
            for (auto &edge:adj[u]) 
            {
                int v=edge.first;
                double p=edge.second;
                double newProb = prob * p;
                if (newProb>best[v]) 
                {
                    best[v]=newProb;
                    pq.push({newProb,v});
                }
            }
        }
        return 0.0;
    }
};