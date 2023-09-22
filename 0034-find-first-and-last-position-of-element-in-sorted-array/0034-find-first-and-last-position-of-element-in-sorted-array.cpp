using namespace std;
class Solution {
public:
    int n;
    int firstOccurance(vector<int> & nums, int target){
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = end - (end - start)/2;
            if(nums[mid]==target){
                ans = mid;
                end = mid-1;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int> & nums, int target){
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = end - (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                start = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> ans;
        int first = firstOccurance(nums, target);
        if(first == -1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int last = lastOccurance(nums, target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};