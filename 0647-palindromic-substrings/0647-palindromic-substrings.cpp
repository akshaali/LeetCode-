class Solution {
public:
    int checkPalindrom(int i, int j, string& s, vector<vector<int>>& dp){
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = s[i] == s[j] ? checkPalindrom(i+1, j-1, s, dp) : 0;
        
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                count += checkPalindrom(i,j,s,dp);
            }
        }
        return count;
    }
};