#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> bfs(const vector<vector<int>> &g, int n)
{
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rail(n + 1);
    vector<vector<bool>> hasRail(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        rail[u].push_back(v);
        rail[v].push_back(u);
        hasRail[u][v] = hasRail[v][u] = true;
    }
    vector<vector<int>> road(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && !hasRail[i][j])
            {
                road[i].push_back(j);
            }
        }
    }
    vector<int> dTrain = bfs(rail, n);
    vector<int> dBus = bfs(road, n);
    if (dTrain[n] == INF || dBus[n] == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << max(dTrain[n], dBus[n]) << "\n";
    }
    return 0;
}
