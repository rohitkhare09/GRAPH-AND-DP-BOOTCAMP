#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, h;
    cin >> n >> d >> h;
    if (d < h || d > 2 * h || (d == 1 && n > 2))
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= h; ++i)
    {
        cout << i << " " << i + 1 << "\n";
    }
    int curr = h + 2;
    for (int i = 0; i < d - h; ++i)
    {
        if (i == 0)
            cout << "1 " << curr << "\n";
        else
            cout << curr - 1 << " " << curr << "\n";
        curr++;
    }
    while (curr <= n)
    {
        cout << "1 " << curr << "\n";
        curr++;
    }
    return 0;
}