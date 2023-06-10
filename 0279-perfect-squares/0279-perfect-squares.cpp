class Solution {
public:
    int solve(int num, int n, vector<vector<int>> &dp){
        if(num==1){
           return n/num;
        }
        if(dp[num][n] != -1) return dp[num][n];
        int notTake = solve(num-1, n,dp);
        int take = 1e9;
        if(n-num*num>=0){
            take = 1 + solve(num, n-num*num,dp);
        }
        int ans = min(take, notTake);
        dp[num][n] = ans;
        return ans;
    }
    int numSquares(int n) {
        int num = sqrt(n); 
        vector<vector<int>>dp(num+1, vector(n+1, -1));
        return solve(num,n,dp);
    }
};