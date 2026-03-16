#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int m, n;
        if (!(cin >> m >> n))
            return 0;
        if (m == 0 && n == 0)
            break;
        vector<vector<pair<int, long long>>> adj(m);
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            total += w;
        }
        vector<bool> used(m, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        long long mst = 0;
        for (int start = 0; start < m; start++)
        {
            if (used[start])
                continue;
            pq.push({0LL, start});
            while (!pq.empty())
            {
                auto [cost, u] = pq.top();
                pq.pop();
                if (used[u])
                    continue;
                used[u] = true;
                mst += cost;
                for (auto &edge : adj[u])
                {
                    int v = edge.first;
                    long long w = edge.second;
                    if (!used[v])
                    {
                        pq.push({w, v});
                    }
                }
            }
        }
        cout << (total - mst) << "\n";
    }
    return 0;
}
