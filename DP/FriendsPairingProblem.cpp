class Solution {
  public:
    int countFriendsPairings(int n) {
    vector<int>dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(1*dp[i-1])+((i-1)*dp[i-2]);
    }
    return dp[n];
    }
};

// class Solution {
//   public:
//     int countFriendsPairings(int n) {
//         if(n<=2) return n;
//         return 1*countFriendsPairings(n-1)+(n-1)*countFriendsPairings(n-2);
//     }
// };

// class Solution {
//   public:
//   int solve(int n,vector<int>&dp)
//   {
//       if(n<=2)
//       {
//           return n;
//       }
//       if(dp[n]!=-1)
//       {
//           return dp[n];
//       }
//       return dp[n]=1*solve(n-1,dp)+(n-1)*solve(n-2,dp);
//   }
//     int countFriendsPairings(int n) {
//         vector<int>dp(n+1,-1);
//         dp[0]=dp[1]=1;
//         return solve(n,dp);
//     }
// };