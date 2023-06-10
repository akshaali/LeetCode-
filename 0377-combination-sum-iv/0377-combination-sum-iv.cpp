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
        vector<int>dp(target+1,0);
        dp[0] = 1;
        for(int i = 1; i<=target; i++){
            long long int ans = 0;
            for(int j = 0; j<n; j++){
                if(i-nums[j]>=0){
                    ans += dp[i-nums[j]];
                }
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};