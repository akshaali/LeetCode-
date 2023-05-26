class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                int m = obstacleGrid.size();
                int n = obstacleGrid[0].size();
                // vector<vector<int>>dp(m, vector<int>(n,0));
                vector<int> prev(n, 0);
                for(int i = 0; i<m; i++){
                        vector<int>curr(n, 0);
                        for(int j = 0; j<n; j++){
                                int right = 0, down = 0;
                                if(i == 0 && j == 0 && obstacleGrid[i][j] != 1){
                                        curr[j] = 1;
                                        continue;
                                }
                                if(i>0 && obstacleGrid[i][j] != 1){
                                      right = prev[j];  
                                }
                                if(j>0 && obstacleGrid[i][j] != 1){
                                        down = curr[j-1];
                                }
                                curr[j] = down + right;
                        }
                        prev = curr;
                }
                int ans = prev[n-1];
                return ans;
            }
};