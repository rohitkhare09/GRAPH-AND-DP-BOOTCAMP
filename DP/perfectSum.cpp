class Solution {
public:

    int solve(vector<int>& arr, int sum, vector<vector<int>>& dp, int idx)
    {
        if(idx == arr.size())
        {
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        int notPick = solve(arr, sum, dp, idx + 1);
        int pick = 0;
        if(arr[idx] <= sum)
            pick = solve(arr, sum - arr[idx], dp, idx + 1);
        return dp[idx][sum] = pick + notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, target, dp, 0);
    }
};