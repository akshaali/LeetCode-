using namespace std;
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>row(n, vector<int>(n, 0));
        vector<vector<int>>col(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int num = matrix[i][j] - 1;
                if(num>=n) return false; 
                if(row[i][num] || col[j][num]) return false;
                col[j][num] = row[i][num] = 1;
            }
        }
        return true;
    }
};