using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;
        int sell = 1;
        int n = prices.size();
        while(buy<sell && sell<n){
            // cout<<"buy: "<<buy<<" sell: "<<sell<<endl;
            if(prices[buy]>prices[sell]){
                buy = sell;
            }
            profit = max(profit, prices[sell]-prices[buy]);
            sell++;
        }
        return profit;
    }
};