class Solution {
public:
    int n;
    int solve(int sum, vector<int>& nums,vector<int>& dp){
        if(sum<0) return 0;
        if(sum == 0) return 1;
        if(dp[sum] != -1) return dp[sum];
        int ans = 0;
        for(int i = 0; i<n; i++){
             if(sum-nums[i]>=0){
                ans += solve(sum-nums[i], nums,dp);
            }
        }
        dp[sum] = ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        vector<int>dp(target+1,-1);
        return solve(target, nums,dp);
    }
};