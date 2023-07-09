class Solution {
public:
    int n;
    int solve(int index, int buy, int canBuy, vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(index == n) return 0;
        if(dp[index][buy][canBuy] != -1) return dp[index][buy][canBuy];
        int _profit1 = 0, _profit2 = 0, _profit3 = 0;
        if(canBuy == 0){
            _profit1 = solve(index+1, buy, 1, prices, dp);
        }else if(buy & canBuy){
            int profit1 = -prices[index] + solve(index+1, 0, canBuy, prices, dp);
            int profit2 = solve(index+1, buy, canBuy, prices, dp);
            _profit2 = max(profit1, profit2);
        } else if(buy == 0){
            int profit1 = prices[index] + solve(index+1, 1, 0, prices, dp);
            int profit2 = solve(index+1, buy, canBuy, prices, dp);
            _profit3 = max(profit1, profit2);
        }
        int ans = max({_profit1, _profit2, _profit3});
        dp[index][buy][canBuy] = ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        return solve(0,1,1,prices, dp);
    }
};