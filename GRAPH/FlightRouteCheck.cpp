#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : graph[u])
        if (!vis[v])
            dfs(v, graph, vis);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), gr(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    dfs(1, g, vis);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    vector<bool> vis2(n + 1, false);
    dfs(1, gr, vis2);

    for (int i = 1; i <= n; i++)
    {
        if (!vis2[i])
        {
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
