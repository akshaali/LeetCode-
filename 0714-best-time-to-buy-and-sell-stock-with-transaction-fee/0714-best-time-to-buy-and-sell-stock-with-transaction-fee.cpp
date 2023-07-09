class Solution {
public:
    int n;
    int fees;
    int solve(int index, vector<int>& prices, int buy,  vector<vector<int>>& dp){
        if(index>=n) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int _profit1 = INT_MIN, _profit2 = INT_MIN;
        if(buy){
            int profit1 = -1*prices[index] + solve(index+1, prices, 0,dp);
            int profit2 = 0 + solve(index+1, prices, buy,dp);
            _profit1 =  max(profit1,profit2);
        }else{
            int profit1 = prices[index] - fees + solve(index+1, prices, 1,dp);
            int profit2 = 0 + solve(index+1, prices, buy,dp);
            _profit2 = max(profit1,profit2);
        }
        int ans = max(_profit1,_profit2);
        dp[index][buy] = ans;
        return ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        fees = fee;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0,prices,1,dp);
    }
};