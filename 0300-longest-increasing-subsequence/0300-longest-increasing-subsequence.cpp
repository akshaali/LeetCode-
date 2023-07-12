// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int maxi = 1;
        for(int index = 0; index<n; index++){
            for(int prevIndex = 0; prevIndex<index; prevIndex++){
                if(nums[prevIndex]<nums[index]){
                    dp[index] = max(dp[index], 1+dp[prevIndex]);
                }
                maxi = max(maxi, dp[index]);
            }
        }
        return maxi;
    }
};