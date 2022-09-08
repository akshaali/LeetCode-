class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Time complexity = O(n) space complexity = O(n)
        // vector<int> out;
        // for(int i = 0; i < n; i++){
        //     out.push_back(nums[i]);
        //     out.push_back(nums[n+i]);
        // }
        // return out;
        
        //Time complexity = O(n) space complexity = O(1)
        for(int i = n; i < nums.size(); i++){
            nums[i] = (nums[i] * 1024) + nums[i-n];
        }
        int index = 0;
        for(int i = n; i < nums.size(); i++, index+=2){
            nums[index] = nums[i]%1024;
            nums[index+1]= nums[i]/1024;
        }
        return nums;
        
    }
};