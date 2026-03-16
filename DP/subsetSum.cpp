class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=sum;j++) 
            {
                bool notPick=dp[i-1][j];
                bool pick=false;
                if(arr[i-1]<=j)
                    pick=dp[i-1][j-arr[i-1]];
                dp[i][j]=pick||notPick;
            }
        }
        return dp[n][sum];
    }
};