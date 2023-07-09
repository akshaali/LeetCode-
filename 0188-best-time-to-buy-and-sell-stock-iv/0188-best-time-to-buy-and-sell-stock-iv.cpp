class Solution {
public:
     int n;
    int solve(int index, vector<int>& prices, int trans, int buy, vector<vector<vector<int>>>& dp){
        if(trans==0) return 0;
        if(index>=n) return 0;
        if(dp[index][trans][buy] != -1) return dp[index][trans][buy];
        int _profit1 = INT_MIN, _profit2 = INT_MIN;
        if(buy){
            int profit1 = -1*prices[index] + solve(index+1, prices, trans-1, 0,dp);
            int profit2 = 0 + solve(index+1, prices, trans, buy,dp);
            _profit1 =  max(profit1,profit2);
        }else{
            int profit1 = prices[index] + solve(index+1, prices, trans-1, 1,dp);
            int profit2 = 0 + solve(index+1, prices, trans, buy,dp);
            _profit2 = max(profit1,profit2);
        }
        int ans = max(_profit1,_profit2);
        dp[index][trans][buy] = ans;
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2*k+1,vector<int>(2,-1)));
        return solve(0,prices,2*k,1,dp);
    }
};