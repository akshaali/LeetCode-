class Solution {
public:
        int solve(int m, int n, int row, int col,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp ){
                if(row>m || col>n) return 0;
                if(obstacleGrid[row][col] == 1) return 0;
                if(row == m && col == n) return 1;
                if(dp[row][col] != -1) return dp[row][col];
                int down = solve(m,n,row, col+1, obstacleGrid, dp);
                int right = solve(m,n, row+1, col, obstacleGrid, dp);
                int ans = down+right;
                dp[row][col] = ans;
                return ans;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                int m = obstacleGrid.size();
                int n = obstacleGrid[0].size();
                vector<vector<int>>dp(m, vector<int>(n,-1));
                int ans = solve(m-1, n-1, 0, 0, obstacleGrid, dp);
                return ans;
            }
};