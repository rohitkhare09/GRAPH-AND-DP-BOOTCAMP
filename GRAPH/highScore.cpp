#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        x = -x;
        edges[i] = {a, b, x};
        adj[a].push_back(b);
    }

    long long inf = 1e17;
    vector<long long> dist(n + 1, inf);
    dist[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = edges[j][0], b = edges[j][1], x = edges[j][2];
            if (dist[a] != inf && dist[a] + x < dist[b])
            {
                dist[b] = dist[a] + x;
            }
        }
    }

    queue<int> cycleNode;
    for (int j = 0; j < m; j++)
    {
        int a = edges[j][0], b = edges[j][1], x = edges[j][2];
        if (dist[a] != inf && dist[a] + x < dist[b])
        {
            cycleNode.push(b);
        }
    }

    vector<bool> vis(n + 1, false);
    bool flag = false;

    while (!cycleNode.empty())
    {
        int curr = cycleNode.front();
        cycleNode.pop();

        if (vis[curr])
            continue;
        vis[curr] = true;

        if (curr == n)
        {
            flag = true;
            break;
        }

        for (int nbr : adj[curr])
        {
            if (!vis[nbr])
                cycleNode.push(nbr);
        }
    }

    if (flag)
    {
        cout << -1 << "\n";
    }
    else
    {
        if (dist[n] == inf)
            cout << -1 << "\n";
        else
            cout << -dist[n] << "\n";
    }

    return 0;
}
