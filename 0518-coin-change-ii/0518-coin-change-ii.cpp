class Solution {
public:
    int n ;
    int solve(int index,int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(index == 0){
            if(amount%coins[index] == 0) return 1;
            return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notTake = solve(index-1, amount,coins, dp);
        int take = 0;
        if(amount-coins[index]>=0){
            take = solve(index, amount-coins[index],coins,dp);
        }
        int ans = notTake + take;
        dp[index][amount] = ans;
        return ans;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};