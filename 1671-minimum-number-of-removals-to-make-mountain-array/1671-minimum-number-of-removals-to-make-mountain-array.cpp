using namespace std;
class Solution {
public:
    vector<int> largestIncSubsq(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int index = 0; index<n; index++){
            for(int prevIndex = 0; prevIndex<index; prevIndex++){
                if(nums[prevIndex]<nums[index] && dp[index]<1+dp[prevIndex]){
                    dp[index] = 1 + dp[prevIndex];                    
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1 = largestIncSubsq(nums);
        reverse(nums.begin(), nums.end());
        vector<int> dp2 = largestIncSubsq(nums);
        reverse(dp2.begin(), dp2.end());
        int maxi = 0;
        for(int i = 0; i<n; i++){
            if(dp1[i] == 1 || dp2[i] == 1) continue;
            int mountain = dp1[i] + dp2[i] - 1;
            maxi = max(maxi, mountain);
        }
        return n - maxi;
    }
};