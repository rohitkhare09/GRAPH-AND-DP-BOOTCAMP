#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
vector<int> g[MAXN];
bool dead[MAXN];
int sub[MAXN];
int n;
int ask(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res;
    if (!(cin >> res))
        exit(0);
    if (res == -1)
        exit(0);
    return res;
}
void dfs_size(int v, int p)
{
    sub[v] = 1;
    for (int u : g[v])
    {
        if (u == p || dead[u])
            continue;
        dfs_size(u, v);
        sub[v] += sub[u];
    }
}
int dfs_centroid(int v, int p, int tot)
{
    for (int u : g[v])
    {
        if (u == p || dead[u])
            continue;
        if (sub[u] > tot / 2)
            return dfs_centroid(u, v, tot);
    }
    return v;
}
void collect_reps(int v, int p, vector<int> &nodes)
{
    nodes.push_back(v);
    for (int u : g[v])
    {
        if (u == p || dead[u])
            continue;
        collect_reps(u, v, nodes);
    }
}
int solve(int entry)
{
    dfs_size(entry, -1);
    int c = dfs_centroid(entry, -1, sub[entry]);

    vector<pair<int, int>> childs;
    for (int u : g[c])
    {
        if (dead[u])
            continue;
        childs.push_back({u, u});
    }
    vector<int> good;
    for (auto &pr : childs)
    {
        int u = pr.second;
        int res = ask(c, u);
        if (res == 1)
        {
            good.push_back(pr.first);
        }
    }
    if ((int)good.size() >= 2)
    {
        cout << "! " << c << endl;
        cout.flush();
        exit(0);
    }
    if ((int)good.size() == 0)
    {
        cout << "! " << c << endl;
        cout.flush();
        exit(0);
    }
    dead[c] = true;
    return solve(good[0]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            dead[i] = false;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve(1);
        cout << "! 1" << endl;
        cout.flush();
    }
    return 0;
}
