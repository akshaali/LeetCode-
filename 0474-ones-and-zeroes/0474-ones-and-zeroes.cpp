using namespace std;
class Solution {
public:
    int size;
    int solve(int index, int m , int n, vector<string>& strs,vector<vector<vector<int>>>& dp){
        if(index == size) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int notTake = solve(index+1, m,n,strs,dp);
        int take = 0;
        int count0 = 0, count1 = 0;
        for(auto ch: strs[index]){
            if(ch == '0') count0++;
            else count1++;
        }
        if(m-count0>=0 && n-count1>=0){
            take = 1 + solve(index+1, m-count0, n-count1, strs,dp);
        }
        int ans = max(take, notTake);
        dp[index][m][n] = ans;
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        vector<vector<vector<int>>>dp(size, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0,m,n,strs,dp);
    }
};