class Solution {
public:
        bool solve(int total, int index,int currSum, vector<int>& nums, vector<vector<int>>&dp){
                if(2*currSum == total) return true;
                if(index>=nums.size()) return false;
                if(dp[index][currSum] != -1) return dp[index][currSum];
                bool notTake = solve(total, index+1, currSum, nums, dp);
                bool take = false;
                if(2*(currSum+nums[index]) <= total){
                        take = solve(total, index+1,currSum+nums[index], nums, dp);
                }
                bool ans = notTake + take;
                dp[index][currSum] = ans;
                return ans;
        }
        
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i<nums.size(); i++) totalSum += nums[i];
        vector<vector<int>>dp(nums.size(), vector<int>(totalSum, -1));
        return solve(totalSum, 0, 0, nums, dp);
    }
};