using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() -1;
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            cout<<mid<<"   "<<start<<"  "<<end<<endl;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) {
                start = mid + 1;
            }else {
                end = mid -1;
            }
        }
        cout<<"left: "<<start<<"   "<<"right: "<<end<<endl;
        return start;
    }
};