#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int n)
{
    if (n==0)
        return 0;
    if (dp[n]!=-1)
        return dp[n];
    int ans = INT_MAX;
    int x=n;
    while (x>0)
    {
        int d=x%10;
        x/=10;
        if (d!=0)
            ans=min(ans,1+solve(n-d));
    }
    return dp[n]=ans;
}
int main()
{
    int n;
    cin>>n;
    dp.resize(n+1,-1);
    cout << solve(n);
}