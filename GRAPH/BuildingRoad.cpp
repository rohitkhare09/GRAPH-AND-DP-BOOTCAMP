#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001];
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> reps;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            reps.push_back(i);
            dfs(i);
        }
    }
    int k = reps.size() - 1;
    cout << k << "\n";
    for (int i = 1; i < reps.size(); i++)
    {
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }
    return 0;
}
