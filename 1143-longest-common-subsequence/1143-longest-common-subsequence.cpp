class Solution {
public:
    int solve(int index1, int index2, string &text1, string &text2,vector<vector<int>>& dp){
        if(index1 < 0 || index2 < 0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] =  1 + solve(index1-1, index2-1, text1, text2, dp);
        }else{
            return  dp[index1][index2] = max(solve(index1-1, index2, text1, text2, dp), solve(index1, index2-1, text1, text2, dp));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2+1, 0), curr(n2+1);
        for(int i1 = 1; i1<=n1; i1++){
            for(int i2 = 1; i2<=n2; i2++){
                if(text1[i1-1] == text2[i2-1]){
                    curr[i2] = 1+ prev[i2-1];
                }else{
                    curr[i2] = max(prev[i2], curr[i2-1]);
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};