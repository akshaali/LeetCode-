class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size(), j = matrix[0].size();
        int start = 0, end = i*j -1;
        while(start<=end){
            int mid = start + (end -start)/2;
            int row = mid/j;
            int col = mid%j;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) end = mid-1;
            else start = mid+1;
        }
        return false;
        
    }
};