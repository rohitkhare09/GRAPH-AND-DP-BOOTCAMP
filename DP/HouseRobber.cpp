class Solution {
public:
int solve(int n,vector<int>&dp,vector<int>&nums)
{
    if(n==0)             //here n is index
    return nums[0];
    if(n==1)
    return max(nums[0],nums[1]);
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=max(solve(n-1,dp,nums),nums[n]+solve(n-2,dp,nums));
}
    int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,-1);
    if(n==1)                        //here n is number of house
    return nums[0];
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    return solve(n-1,dp,nums);
    }
};