class Solution {
public:
    int n;
    int solve(int index, vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(index == n){
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int pass1 = costs[0] + solve(index+1,days,costs,dp);
        int i;
        for(i= index; i<n && days[i]<days[index]+7; i++);
        int pass2 = costs[1] + solve(i, days,costs,dp);
        for(i = index; i<n && days[i]<days[index]+30; i++);
        int pass3 = costs[2] + solve(i,days,costs,dp);
        int ans = min({pass1, pass2, pass3});
        dp[index] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int>dp(n+1, -1);
        return solve(0,days,costs,dp);
    }
};