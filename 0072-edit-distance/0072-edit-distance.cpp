class Solution {
public:
    int solve(int index1, int index2, string word1, string word2,vector<vector<int>>&dp){
        // if(index1<0 && index2<0) return 0;
        // if(index1<0 || index2<0) return abs(index1-index2);
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
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
        vector<int>prev(n2+1, 0), curr(n2+1, 0);
        for(int index2 = 0; index2<=n2; index2++) prev[index2] = index2;
        for(int index1 = 1; index1<=n1; index1++){
            curr[0] = index1;
            for(int index2 = 1; index2<=n2; index2++){
                if(word1[index1-1] == word2[index2-1]){
                    curr[index2] = prev[index2-1];
                }else{
                     curr[index2] = 1 + min({prev[index2-1], prev[index2], curr[index2-1]});
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};