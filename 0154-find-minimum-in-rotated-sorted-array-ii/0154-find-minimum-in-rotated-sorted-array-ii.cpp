class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid=0;
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