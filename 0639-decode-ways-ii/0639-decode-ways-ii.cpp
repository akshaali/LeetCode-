class Solution {
public:
    int mod = 1e9+7;
    int n;
    int solve(int index,string &s,vector<int>&dp){
        if(index >= n) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];
        int res = 0;
        
        if(s[index] == '*'){
            int i = 9;
            while(i--){
                res = (res%mod + solve(index+1, s, dp)%mod)%mod;
            }
        }else{
            res = (res%mod+ solve(index+1,s,dp)%mod)%mod;
        }
        
        if(index<n-1 && s[index] == '1' && s[index+1] == '*'){
             int i = 9;
            while(i--){
                res = (res%mod + solve(index+2, s, dp)%mod)%mod;
            }
        }else if(index<n-1 && s[index] == '2' && s[index+1] == '*'){
            int i = 6;
            while(i--){
                res = (res%mod + solve(index+2, s, dp)%mod)%mod;
            }
        }else if(index<n-1 && s[index] == '*' && s[index+1] == '*'){
            int i = 15;
             while(i--){
                res = (res%mod + solve(index+2, s, dp)%mod)%mod;
            }
        }else if(index<n-1 && s[index] == '*' && s[index+1]>='0' && s[index+1]<'7'){
            int i = 2;
            while(i--){
                res = (res%mod + solve(index+2,s,dp)%mod)%mod;
            }
        }else if(index<n-1 && s[index] == '*'){
            res = (res%mod + solve(index+2,s,dp)%mod)%mod;
        }
        else if(index < n-1 && (s[index]=='1'|| (s[index]=='2'&& s[index+1]<'7'))){
            res = (res%mod + solve(index+2,s,dp)%mod)%mod;
        }
        
        dp[index] = res%mod;
        return res%mod;
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n,-1);
        return solve(0, s, dp);
    }
};