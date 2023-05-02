using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int square[9][9] = {0};
        
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.') continue;
                int k = (i/3)*3 + j/3;
                int num = board[i][j] - '0' -1;
                if(col[j][num] || row[i][num] || square[k][num]) return false;          
                col[j][num] = row[i][num] = square[k][num]= 1;
                
            }
        }
        return true;
        
    }
};