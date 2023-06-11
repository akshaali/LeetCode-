class Solution {
public:
    int maxi = 0;
    int m, n;
    int solve(int row, int col, vector<vector<char>>& matrix,vector<vector<int>>&dp){
        if(row>=m || col>=n){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int right = solve(row, col+1, matrix,dp);
        int diagonal = solve(row+1, col+1,matrix,dp);
        int down = solve(row+1, col, matrix,dp);
        if(matrix[row][col] == '1'){
            int ans = 1+ min({right, diagonal, down});
            maxi = max(maxi, ans);
            dp[row][col]= ans;
            return ans;
        }else{
            dp[row][col] = 0;
            return 0;
        }
        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        solve(0,0,matrix,dp);
        return maxi*maxi;
    }
};