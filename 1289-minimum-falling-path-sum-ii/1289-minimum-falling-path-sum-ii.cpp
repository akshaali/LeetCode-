using namespace std;
class Solution {
public:
         void print(vector<int> arr){
                cout<<"[ ";
                for(auto a: arr){
                        cout<<a<<", ";
                }
                cout<<"]"<<endl;
        }
        int minimum(vector<int> arr){
                int mini = INT_MAX;
                for(auto a: arr){
                        mini = min(mini, a);
                }
                return mini;
        }
    int minFallingPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>>dp(m, vector<int>(n,-1e9));
            vector<int>prev(n, 0);
            for(int i = 0; i<n; i++){
                    vector<int>curr(n,0);
                    for(int j = 0; j<n; j++){
                            int mini = INT_MAX;
                            if(i == 0){
                                    curr[j] = grid[i][j];
                                    continue;
                            }
                            for(int k = 0; k<n; k++){
                                   if(k != j){
                                          mini = min(mini, grid[i][j] + prev[k]);
                                   }
                            }
                            curr[j] = mini;
                    }
                    prev = curr;
                }
            // print(prev);
            int ans = minimum(prev);
            return ans;
    }
};










