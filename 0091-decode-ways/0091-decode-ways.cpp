class Solution {
public:
    int n;
    int solve(int index,string &s,vector<int>&dp){
        if(index == n) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];
        int res = solve(index+1,s,dp);
        if( index < n-1 && (s[index]=='1'|| (s[index]=='2'&& s[index+1]<'7'))){
            res += solve(index+2,s,dp);
        }
        dp[index] = res;
        return res;
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n,-1);
        return solve(0, s, dp);
    }
};