class Solution {
public:
    int fib(int n) {
        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // return fib(n-1) + fib(n-2);
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
    int solve(int n, vector<int> &dp){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
};