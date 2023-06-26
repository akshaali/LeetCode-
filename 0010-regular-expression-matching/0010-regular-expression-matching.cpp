using namespace std;
class Solution {
public:
     bool solve(int i, int j,string & s, string & p,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            // cout<<i<<" "<<j<<endl;
            // if(p[j] == '*' && j == 1) return true;
            for(int k = j; k>=0; k-=2){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '.'){
            return dp[i][j] = solve(i-1, j-1, s, p,dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(i, j-2, s,p,dp) || ((s[i] == p[j-1] || p[j-1] == '.') && solve(i-1, j, s, p,dp));
        }
        dp[i][j] = false;
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1,s,p,dp);
    }
};