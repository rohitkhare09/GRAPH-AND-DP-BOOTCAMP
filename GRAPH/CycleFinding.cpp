#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<long long> c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int node = -1;
    for (int i = 1; i <= n; i++)
    {
        node = -1;
        for (int j = 0; j < m; j++)
        {
            int u = a[j];
            int v = b[j];
            long long w = c[j];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                node = v;
            }
        }
    }
    if (node == -1)
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        node = parent[node];
    }
    vector<int> cycle;
    int cur = node;
    do
    {
        cycle.push_back(cur);
        cur = parent[cur];
    } 
    while (cur != node);
    cycle.push_back(node);
    reverse(cycle.begin(), cycle.end());
    cout << "YES\n";
    for (int v : cycle)
    {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
