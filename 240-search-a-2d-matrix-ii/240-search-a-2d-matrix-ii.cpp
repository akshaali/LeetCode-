class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        
        while(col>=0 and row<=matrix.size()-1)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                row++;
                
            }
            else if(matrix[row][col]>target)
            {
               col--;   
            }
        }
        
        return false;
    }
};