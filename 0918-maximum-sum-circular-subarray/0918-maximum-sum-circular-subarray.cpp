class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxSum = nums[0], currMax = 0;
        int minSum = nums[0], currMin = 0;
        int total = 0;
        for(auto num: nums){
            total += num;
            currMax = max(currMax+num, num);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+num, num);
            minSum = min(currMin, minSum);
        }
        ans = maxSum>0 ? max(maxSum, total-minSum): maxSum;
        return ans;
    }
};