class Solution {
public:
int solve(int index, int sum, int n, int target,vector<int> &nums,vector<unordered_map<int, int>>&dp){
    if(index>=n){
        if(sum == target) return 1;
        else return 0;
    }
    if(dp[index].count(sum)) return dp[index][sum];
    int takeAdd = solve(index+1, sum+nums[index], n, target, nums, dp);
    int takeSub = solve(index+1, sum-nums[index], n, target, nums, dp);
    int ans = takeAdd+takeSub;
    dp[index][sum] = ans;
    return ans;
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
        // vector<vector<int>>dp(n, vector<int>(target+1, 0));
        vector<unordered_map<int, int>>dp(n);
            return solve(0,0,n,target, nums,dp);
    }
};