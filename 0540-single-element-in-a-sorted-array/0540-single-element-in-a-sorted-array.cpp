using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() -1;
        while(start<end){
            int mid = start+ (end-start)/2;
            if((mid%2 == 0 && nums[mid+1] == nums[mid]) || (mid%2 == 1 && nums[mid-1] == nums[mid])){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return nums[start];
    }
};