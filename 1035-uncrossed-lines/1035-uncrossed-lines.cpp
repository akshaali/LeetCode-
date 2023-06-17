class Solution {
public:
    int solve(int index1, int index2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(nums1[index1] == nums2[index2]){
            return dp[index1][index2]= 1 + solve(index1-1, index2-1, nums1, nums2,dp);
        }
        return dp[index1][index2]= max(solve(index1-1, index2, nums1, nums2,dp), solve(index1, index2-1, nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1, nums1, nums2,dp);
    }
};