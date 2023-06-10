class Solution {
public:
    
    int numSquares(int n) {
        int num = sqrt(n); 
        vector<vector<int>>dp(num+1, vector(n+1, 0));
        for(int i = 0; i<=n; i++){
            dp[1][i] = i;
        }
        for(int i =2; i<=num; i++){
            for(int j = 0; j<=n; j++){
                int notTake = dp[i-1][j];
                int take = 1e9;
                if(j-i*i>=0){
                    take = 1 + dp[i][j-i*i];
                }
                dp[i][j] = min(take, notTake);
            }
        }
        return dp[num][n];
    }
};