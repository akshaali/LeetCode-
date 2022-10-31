using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size(), col=grid[0].size();
        for(int i = 0; i<row; i++){
            ans += (col - firstNegativeBinarySearch(grid[i], col));
            // cout<<firstNegativeBinarySearch(grid[i], col)<<endl;
        }
        return ans;
    }
    int firstNegativeBinarySearch(vector<int> arr, int col){
        int firstNegative = col;
        int start = 0, end = arr.size()-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(arr[mid]<0){
                firstNegative = mid;
                end = mid-1;
            }else if(arr[mid]>=0){
                start = mid+1;
            }
        }
        return firstNegative;
    }
};