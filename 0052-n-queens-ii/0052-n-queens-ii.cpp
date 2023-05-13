class Solution {
public:
        bool isSafe(vector<string> board, int row, int col, int n){
        int dupRow = row;
        int dupCol = col;
        //check row
        while(col>=0){
            if(board[row][col--] == 'Q') return false;
        }
        
        //check upper diagonal
         row = dupRow;
         col = dupCol;
        while(col>=0 && row>=0){
            if(board[row--][col--] == 'Q') return false;
        }
        
        //check lower doagonal
        row = dupRow;
        col = dupCol;
        while(col>=0 && row<n){
            if(board[row++][col--] == 'Q') return false;
        }
        return true;
        
    }
    
    void solve(int col, int &ans,vector<string> board, int n ){
        if(col == n){
            ans++;
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0; i<n; i++) board[i] = s;
        solve(0, ans, board, n);
        return ans;
    }
};