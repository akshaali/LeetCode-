class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int temp = abs(nums[i]);
           nums[temp-1] = nums[temp-1] > 0 ? nums[temp-1] * -1: nums[temp-1];
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
        
    }
};