class Solution {
public:
    int solve(int index1, int index2, string word1, string word2,vector<vector<int>>&dp){
        if(index1<0 && index2<0) return 0;
        if(index1<0 || index2<0) return abs(index1-index2);
        if(dp[index1][index2] != -1) return dp[index1][index2];
        int c1 = 1e9;
        if(word1[index1] == word2[index2]){
            c1 = solve(index1-1, index2-1, word1, word2,dp);
        }
        int c2 = 1+solve(index1-1, index2-1, word1, word2,dp);
        int c3 = 1+solve(index1-1, index2, word1, word2, dp);
        int c4 = 1+ solve(index1, index2-1, word1, word2, dp);
        int ans = min({c1, c2, c3, c4});
        dp[index1][index2] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        int ans = solve(n1-1, n2-1, word1, word2, dp);
        return ans;
    }
};