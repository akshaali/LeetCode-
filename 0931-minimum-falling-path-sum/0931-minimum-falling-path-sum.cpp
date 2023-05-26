class Solution {
public:
        int solve(int m,int n, int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp){
                if(row>m || col>n || col<0 || row<0) return 1e9;;
                if(row == m) return matrix[row][col];
                if(dp[row][col] != 1e9) return dp[row][col];
                int down = matrix[row][col] + solve(m,n,row+1, col,matrix, dp);
                int diagL = matrix[row][col] + solve(m,n,row+1,col-1, matrix, dp);
                int diagR = matrix[row][col] + solve(m,n,row+1,col+1,matrix, dp);
                int ans = min(down, min(diagL, diagR));
                dp[row][col] = ans;
                return ans;
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
                int m = matrix.size();
                int n = matrix[0].size();
                int mini= INT_MAX;
                vector<vector<int>>dp(m, vector<int>(n,1e9));
                for(int i = 0; i<n; i++){
                       int value = solve(m-1,n-1,0,i,matrix, dp);
                        mini = min(mini, value);
                }
                return mini;
    }
};