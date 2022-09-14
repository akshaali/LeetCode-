class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int total = n * n;
        int count = 0;
        //indexes
        int startRow = 0;
        int endRow = n -1;
        int startCol = 0;
        int endCol = n -1;
        while(count<total){
            //adding starting row
            for(int index = startCol; count<total && index<=endCol; index++){
                count++;
                res[startRow][index] = count;
            }
            startRow++;
            //print ending collumn
            for(int index = startRow; count<total && index<=endRow; index++){
                count++;
                res[index][endCol] = count;
            }
            endCol--;
            //print ending row
            for(int index = endCol; count<total && index>=startCol; index--){
                count++;
                res[endRow][index] = count;
            }
            endRow--;
            //print starting column
            for(int index = endRow; count<total && index>=startRow; index--){
                count++;
                res[index][startCol] = count;
            }
            startCol++;
        }
        return res;
        
        
    }
};