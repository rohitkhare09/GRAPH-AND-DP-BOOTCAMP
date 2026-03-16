class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n=wt.size();
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for(int w=wt[0];w<=W;w++)
    {
        dp[0][w]=val[0];
    }
        for(int idx=1;idx<n;idx++)
        {
            for(int w=0;w<=W;w++)
            {
                int notTake=0+dp[idx-1][w];
                int take=INT_MIN;
                if(wt[idx]<=w)
                {
                    take=val[idx]+dp[idx-1][w-wt[idx]];
                }
                dp[idx][w]=max(take,notTake);
            }
        }
    return dp[n-1][W];
    }
};