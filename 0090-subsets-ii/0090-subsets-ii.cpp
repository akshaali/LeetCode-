class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        sort(nums.begin(), nums.end());
        solve(nums, output, index, ans);
        return ans;
    }
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
         //exclude
        output.pop_back();
        while(index +1<nums.size() && nums[index] == nums[index+1]) index++;
        solve(nums, output, index+1, ans);
    }
};