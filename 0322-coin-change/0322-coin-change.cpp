class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int am = 1; am<=amount; am++){
            for(int i = 0; i<coins.size(); i++){
                if(am-coins[i]>=0 && dp[am-coins[i]] !=INT_MAX){
                    dp[am] = min(dp[am], 1 + dp[am-coins[i]]);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};