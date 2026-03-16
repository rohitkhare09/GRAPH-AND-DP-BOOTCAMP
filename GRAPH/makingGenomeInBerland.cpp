#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> adj(26, vector<bool>(26, false));
    vector<int> indeg(26, 0);
    vector<bool> present(26, false);
    while (n--)
    {
        string s;
        cin >> s;
        for (char c : s)
            present[c - 'a'] = true;
        for (int i = 0; i < (int)s.size(); i++)
        {
            for (int j = i + 1; j < (int)s.size(); j++)
            {
                int u = s[i] - 'a';
                int v = s[j] - 'a';
                if (!adj[u][v])
                {
                    adj[u][v] = true;
                    indeg[v]++;
                }
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (present[i] && indeg[i] == 0)
            q.push(i);
    }
    string ans;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(char('a' + u));
        for (int v = 0; v < 26; v++)
        {
            if (adj[u][v])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}