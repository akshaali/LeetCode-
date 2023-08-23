class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        for(int s = 0; s<= m+n-2; s++){
            for(int x = 0; x<=s; x++){
                int i = x;
                int j = s-x;
                if(s%2 == 0) swap(i,j);
                if(i>=m || j>=n) continue;
                ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
};