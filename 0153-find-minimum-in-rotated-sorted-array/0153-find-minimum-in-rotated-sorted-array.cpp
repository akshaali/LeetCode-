class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() -1;
        // int mid = start + (end - start)/2;
        while(start<end){
             int mid = start + (end - start)/2;
            if(nums[mid]>=nums[0] && nums[mid]<=nums[nums.size()-1]){
                return nums[0];
            }
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }else{
                end = mid;
            }
            mid = start + (end - start)/2;
            }
        return nums[start];
        
    }
};