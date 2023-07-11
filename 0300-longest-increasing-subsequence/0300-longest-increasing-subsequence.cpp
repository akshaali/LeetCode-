class Solution {
public:
    int n;
    int solve(int index, int prevIndex, vector<int>& nums, vector<vector<int>>& dp){
        if(index == n) return 0;
        if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex+1];
        int take = INT_MIN;
        int notTake = 0 + solve(index+1, prevIndex, nums, dp);
        if(prevIndex == -1 || nums[prevIndex] < nums[index]){
            take = 1 + solve(index+1, index, nums, dp);
        }
        int ans = max(take, notTake);
        dp[index][prevIndex+1] = ans;
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, -1, nums, dp);
    }
};