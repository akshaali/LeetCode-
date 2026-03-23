class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = low;
        int ans = INT_MAX;
        while(low<=high){
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                return ans;
            }
            mid = low + (high-low)/2;
            if(nums[mid]>=nums[low]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return min(nums[mid], ans);
        
    }
};