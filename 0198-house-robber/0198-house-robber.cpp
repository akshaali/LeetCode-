//bottom -Up DP() - space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1, -1);
        // dp[0] = 0;
        // dp[1] = nums[0];
        int prev1 = 0;
        int prev2 = nums[0];
        
        for(int i = 2; i<=n; i++){
            int curr = max(prev2, nums[i-1] + prev1);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};