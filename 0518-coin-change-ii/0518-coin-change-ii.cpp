class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1, 0));
        for(int j = 0; j<=amount; j++){
            dp[0][j] = (j%coins[0] == 0) ? 1: 0;
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j-coins[i]>=0){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};