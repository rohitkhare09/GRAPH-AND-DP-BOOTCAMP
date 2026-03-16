class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= target; j++) 
            {
                bool notPick = dp[i-1][j];
                bool pick = false;
                if (nums[i-1] <= j)
                    pick = dp[i-1][j - nums[i-1]];
                dp[i][j] = pick || notPick;
            }
        }
        return dp[n][target];
    }
};