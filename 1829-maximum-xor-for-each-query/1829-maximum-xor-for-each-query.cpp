class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //very nice solution 
        int maxSetBit =( 1<<maximumBit) -1; 
        vector<int> ans(nums.size());
        int val = maxSetBit;
        for(int i = 0; i < nums.size(); i++){
            val ^= nums[i];
            ans[nums.size()-1-i] = val ;
        }
        return ans;
        
    }
};