#include <bits/stdc++.h>
using namespace std;
const int MAXN = INT_MAX;
vector<int> adj[MAXN];
int distA[MAXN], distB[MAXN];
int n, x;
void bfs(int start, int dist[])
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        dist[i] = -1;
    dist[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1, distA);
    bfs(x, distB);
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        if (distB[i] < distA[i])
        {
            best = max(best, distA[i]);
        }
    }
    cout << 2 * best << endl;
}
