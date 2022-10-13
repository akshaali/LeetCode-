class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min1 = nums[0], min2 = nums[1];
        int max1 = nums[nums.size() -1], max2 = nums[nums.size()-2];
        return(max1*max2 - min1*min2);   
    }
};