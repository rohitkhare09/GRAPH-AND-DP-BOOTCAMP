#include <bits/stdc++.h>
using namespace std;
void dfs1(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = true;
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<bool> &vis, vector<vector<int>> &rev, vector<int> &comp, int cid)
{
    vis[node] = true;
    comp[node] = cid;
    for (int it : rev[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, rev, comp, cid);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    stack<int> st;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(i, vis, adj, st);
        }
    }
    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++)
    {
        for (int j : adj[i])
        {
            rev[j].push_back(i);
        }
    }
    vis.assign(n, false);
    vector<int> comp(n, 0);
    int cid = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cid++;
            dfs2(node, vis, rev, comp, cid);
        }
    }
    cout << cid << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << comp[i] << " ";
    }
    cout << "\n";

    return 0;
}
