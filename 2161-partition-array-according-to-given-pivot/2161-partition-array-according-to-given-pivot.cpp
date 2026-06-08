class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int low = 0;
        int same = 0;
        int high = 0;
        
        for(int i = 0; i<n; i++){
            if(nums[i]<pivot)low++;
            else if(nums[i] == pivot) same++;
            else high++;
        }
        high = low+same;
        same = low;
        low = 0;
        vector<int>ans(n, -1);
        for(int i =0; i<n; i++){
            if(nums[i]<pivot){
                ans[low] = nums[i];
                low++;
            }else if(nums[i] == pivot){
                ans[same] = nums[i];
                same++;
            }
            else{
                ans[high] = nums[i];
                high++;
            }
        }
        return ans;
    }
};