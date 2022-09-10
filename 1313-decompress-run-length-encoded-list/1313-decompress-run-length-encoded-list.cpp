class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>res;
        for(int i = 0; i<nums.size(); i += 2){
            int num = nums[i];
            while(num>0){
                res.push_back(nums[i+1]);
                num = num - 1;
            }
        }
        return res;
    }
};