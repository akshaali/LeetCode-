class Solution {
public:
    int solve(int start, int end,string& s, vector<vector<int>>& dp){
        if(start> end) return 0;
        if(start == end) return s[start] == s[end];
        if(dp[start][end] != -1) return dp[start][end];
        if(s[start] == s[end]) {
            return dp[start][end] = 2+solve(start+1, end-1, s,dp);
        }else{
            return dp[start][end] = max(solve(start+1, end, s,dp), solve(start, end-1, s,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};