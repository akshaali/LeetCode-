class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>cnt(n,1);
        int maxi = 1;
        for(int index = 0; index<n; index++){
            for(int prevIndex = 0; prevIndex<index; prevIndex++){
                if(nums[prevIndex]<nums[index]){
                    if(1+dp[prevIndex] > dp[index]){
                        dp[index] = 1+dp[prevIndex];
                        cnt[index] = cnt[prevIndex];
                    }else if(1+dp[prevIndex] == dp[index]){
                        cnt[index] += cnt[prevIndex];
                    }
                }
            }
            maxi = max(maxi, dp[index]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};