class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                int m = obstacleGrid.size();
                int n = obstacleGrid[0].size();
                vector<vector<int>>dp(m, vector<int>(n,0));
                for(int i = 0; i<m; i++){
                        for(int j = 0; j<n; j++){
                                int right = 0, down = 0;
                                if(i == 0 && j == 0 && obstacleGrid[i][j] != 1){
                                        dp[i][j] = 1;
                                        continue;
                                }
                                if(i>0 && obstacleGrid[i][j] != 1){
                                      right = dp[i-1][j];  
                                }
                                if(j>0 && obstacleGrid[i][j] != 1){
                                        down = dp[i][j-1];
                                }
                                dp[i][j] = down + right;
                        }
                }
                int ans = dp[m-1][n-1];
                return ans;
            }
};