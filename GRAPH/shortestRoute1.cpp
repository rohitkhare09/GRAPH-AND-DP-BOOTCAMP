#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    pq.push({0, 1});
    while (!pq.empty())
    {
        long long curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (curDist > dist[u])
            continue;
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            long long weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}