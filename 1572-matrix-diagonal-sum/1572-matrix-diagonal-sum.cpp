class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int size = mat.size();
        for(int i = 0; i<size; i++){
            for(int j = 0; j < size; j++){
                if((i+j) == size - 1 || (i==j)){
                    ans += mat[i][j];
                }
            }
        }
        return ans; 
    }
};