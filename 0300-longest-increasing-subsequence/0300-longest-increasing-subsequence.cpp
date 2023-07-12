// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int>after(n+1, 0), curr(n+1, 0);
        for(int index = n-1; index>=0; index--){
            for(int prevIndex = index-1; prevIndex>=-1; prevIndex--){
                int take = INT_MIN;
                int notTake = 0 + after[prevIndex+1];
                if(prevIndex == -1 || nums[prevIndex] < nums[index]){
                    take = 1 + after[index+1];
                }
                int ans = max(take, notTake);
                curr[prevIndex+1] = ans;
            }
            after = curr;
        }
        return after[0];
    }
};