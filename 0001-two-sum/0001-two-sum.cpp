class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int numToTarget = target-nums[i];
            if(map.count(numToTarget)){
               ans.push_back(i);
                ans.push_back(map[numToTarget]);
            }
            map[nums[i]] = i;
        }
        return ans;
        
    }
};