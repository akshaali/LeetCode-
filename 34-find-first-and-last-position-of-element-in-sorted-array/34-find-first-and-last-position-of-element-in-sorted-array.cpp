using namespace std;

        int firstOccurance(vector<int>& nums, int target){
            int left = 0, right = nums.size() - 1, first = -1;
             while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                first = mid;
                right = mid -1;
            }else if(nums[mid] > target){
                right = mid -1;
            }else {
                left = mid + 1;
            }
        }   
            return first;
        }
        
        int lastOccurance(vector<int>& nums, int target){
            int left = 0, right = nums.size() - 1, last = -1;
             while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                last = mid;
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid -1;
            }else {
                left = mid + 1;
            }
        }   
            return last;
        }
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        cout <<firstOccurance(nums, target)<<endl; 
        cout <<lastOccurance(nums, target)<<endl;
        ans.push_back(firstOccurance(nums, target));
        ans.push_back(lastOccurance(nums, target));
        return ans;
    }
};