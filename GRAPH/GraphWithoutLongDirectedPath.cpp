#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 200000;
int n, m;
vector<int> adj[MAXN + 1];
pair<int, int> edges[MAXN + 1];
int color[MAXN + 1];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        color[i] = -1;
    for (int start = 1; start <= n; start++)
    {
        if (color[start] != -1)
            continue;
 
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
 
            for (int v : adj[u])
            {
                if (color[v] == -1)
                {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        if (color[u] == 0 && color[v] == 1)
            cout << '0';
        else
            cout << '1';
    }
    cout << "\n";
    return 0;
}