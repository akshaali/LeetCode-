using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() -1, mid;
        mid = (left+right)/2;
        while(left < right){
             // mid = (left+right)/2;
            cout<<mid<<" "<<left<<" "<<right<<endl;
            if(arr[mid] < arr[mid+1]){
                left = mid+1;
            }else{
                right = mid;
            }
           mid = (left+right)/2;
        }
        return mid;
    }
};