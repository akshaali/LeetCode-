class Solution {
public:
    int n;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int>dp(n+1, -1);
        dp[n] = 0;
        for(int index = n-1; index>=0; index--){
            int pass1 = costs[0] + dp[index+1];
            int i;
            for(i= index; i<n && days[i]<days[index]+7; i++);
            int pass2 = costs[1] + dp[i];
            for(i = index; i<n && days[i]<days[index]+30; i++);
            int pass3 = costs[2] + dp[i];
            int ans = min({pass1, pass2, pass3});
            dp[index] = ans;
        }
        return dp[0];
    }
};