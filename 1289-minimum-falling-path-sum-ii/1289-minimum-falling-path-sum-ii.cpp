using namespace std;
class Solution {
public:
        int solve(int m,int n, int row, int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
                // cout<<"row: "<<row<<" col: "<<col<<endl;
                if(row>m || col>n || col<0 || row<0) return 1e9;
                if(row == m) return matrix[row][col];
                if(dp[row][col] != -1e9) return dp[row][col];
                int mini = INT_MAX;
                for(int j = 0; j<=n; j++){
                        // cout<<"jj "<<j<<endl;
                        if(j != col){
                        int value = INT_MAX;
                           value  = matrix[row][col] + solve(m,n,row+1, j,matrix, dp);
                        // cout<<"Valueeeee: "<<value<<" row: "<<row<<" col: "<<col<<endl;
                                mini = min(mini, value);
                        }
                         
                }
                dp[row][col] = mini;
                return mini;
        }
    int minFallingPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
                int n = grid[0].size();
                int mini= INT_MAX;
                vector<vector<int>>dp(m, vector<int>(n,-1e9));
                for(int i = 0; i<n; i++){
                       int value = solve(m-1,n-1,0,i,grid, dp);
                        // cout<<"value: "<<value<<endl;
                        mini = min(mini, value);
                }
                return mini;
        
    }
};