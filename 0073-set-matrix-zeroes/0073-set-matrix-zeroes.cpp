using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<array<int, 2>> zeroes;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                   array<int, 2> rowCol= {i,j};
                    zeroes.push_back(rowCol);
                }
            }
        }
        for(auto rc: zeroes){
            cout<<rc[0]<<" "<<rc[1]<<endl;
            for(int r = 0; r <row;r++ ){
                matrix[r][rc[1]] = 0;
            }
            for(int c = 0; c <col;c++ ){
                matrix[rc[0]][c] = 0;
            }
        }
        
    }
};