class Solution {
public:
    int m,n;
    string word;
    int len;
    bool solve(vector<vector<char>>& board, int row, int col,int index){
        if(index >= len) return true;
        if(row<0 || row>=m) return false;
        if(col<0 || col>=n) return false;
        if(board[row][col] != word[index]) return false;
        // if(isVisited[row][col] == 1) return false;
        // int ind = index;
        // if(board[row][col] == word[index]){
        //     ind++;
        // }
        char val =  board[row][col];
        board[row][col] = '*';
        bool down = solve(board, row+1, col, index+1);
        bool up = solve(board, row-1, col, index+1);
        bool left = solve(board, row, col-1, index+1);  
        bool right = solve(board, row, col+1, index+1);
        bool ans = down || up || right || left;
        board[row][col] = val;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string _word) {
        m = board.size();
        n = board[0].size();
        word = _word;
        len = _word.size();
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(board[i][j] == word[0] && solve(board, i, j, 0)) return true;
        return false;
    }
};