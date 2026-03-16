class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
        return 0;
    int sum = (target + totalSum) / 2;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (nums[0] != 0 && nums[0] <= sum)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            int notTake = dp[i - 1][s];
            int take = 0;
            if (nums[i] <= s)
                take = dp[i - 1][s - nums[i]];
            dp[i][s] = take + notTake;
        }
    }
    return dp[n - 1][sum];
    }
};