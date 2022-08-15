class Solution {
public:
    int findMin(vector<int>& nums) {
        // int start = 0, end = nums.size() -1;
        // int mid = start + (end - start)/2;
        // while(start<end){
        //     if(nums[mid]>=nums[0] && nums[mid]<nums[nums.size()-1]){
        //         return nums[0];
        //     }
        //     if(nums[mid]>=nums[0]){
        //         start = mid+1;
        //     }else{
        //         end = mid;
        //     }
        //     mid = start + (end - start)/2;
        //     }
        // return nums[start];
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right])left=mid+1;
            else if(nums[mid]<nums[right])right=mid;
            else{
                right--;
            }
        }
        return nums[right];
    }
};