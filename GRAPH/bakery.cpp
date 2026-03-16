#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<bool> hasBakery(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        hasBakery[x] = true;
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        if (hasBakery[u] != hasBakery[v])
        {
            ans = min(ans, w);
        }
    }
    if (ans == LLONG_MAX)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
