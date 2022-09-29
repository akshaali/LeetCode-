class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ans((row-2), vector<int>(col-2));
        for(int i = 0; i<row-2; i++){
            for(int j = 0; j<col-2; j++){
                for(int ii = i; ii< i+3; ii++){
                    for(int jj = j; jj<j+3; jj++){
                        ans[i][j] = max(ans[i][j], grid[ii][jj]);
                    }
                }
            }
        }
        return ans;   
    }
};