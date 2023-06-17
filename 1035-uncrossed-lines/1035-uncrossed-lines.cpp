class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        for(int index1 = 1; index1<=n1; index1++){
            for(int index2 = 1; index2<=n2; index2++){
                if(nums1[index1-1] == nums2[index2-1]){
                    dp[index1][index2]= 1 + dp[index1-1][index2-1];
                }else{
                    dp[index1][index2]= max(dp[index1-1][index2], dp[index1][index2-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};