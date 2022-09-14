class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = rows * cols;
        int count = 0;
        //indexes
        int startRow = 0;
        int endRow = rows -1;
        int startCol = 0;
        int endCol = cols -1;
        while(count<total){
            //print starting row
            for(int index = startCol; count<total && index<=endCol; index++){
                res.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;
            //print ending collumn
            for(int index = startRow; count<total && index<=endRow; index++){
                res.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;
            //print ending row
            for(int index = endCol; count<total && index>=startCol; index--){
                res.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;
            //print starting column
            for(int index = endRow; count<total && index>=startRow; index--){
                res.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }
        return res;
        
    }
};