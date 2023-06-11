class Solution {
public:
    int maxi = 0;
    int m, n;
    
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int row = m-1; row>=0; row--){
            for(int col = n-1; col>=0; col--){
                int right = dp[row][col+1];
                int diagonal = dp[row+1][col+1];
                int down = dp[row+1][col];
                if(matrix[row][col] == '1'){
                    int ans = 1+ min({right, diagonal, down});
                    maxi = max(maxi, ans);
                    dp[row][col]= ans;
                }else{
                    dp[row][col] = 0;
                }
            }
        }
        return maxi*maxi;
    }
};