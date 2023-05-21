class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int> &dp){
        if(index == 0) return nums[0];
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = solve(index-2, nums, dp) + nums[index];
        int notPick = solve(index-1, nums, dp);
        int ans = max(pick, notPick);
        dp[index] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(n-1, nums, dp);
    }
};