class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high = 0;
        for(auto i: nums){
            if(i<pivot) low++;
            else if(i == pivot) same++;
        }
        high = low+same;
        same = low;
        low = 0;
         vector<int> ans(nums.size());
        for(auto i: nums){
            if(i<pivot){
                ans[low++] = i;
            }else if(i == pivot){
                ans[same++] = i;
            }else{
                ans[high++] = i;
            }
        }
        return ans;
        
    }
};