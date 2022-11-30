class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, currMax = 0;
        for(int i = 0; i<n; i++){
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            if(currMax<0){
                currMax = 0;
            }
        }
        int minSum = INT_MAX, currMin = 0;
        for(int i = 0; i<n; i++){
            currMin += nums[i];
            minSum = min(minSum, currMin);
            if(currMin>0){
                currMin = 0;
            }
        }
        return max(abs(minSum), abs(maxSum));
    }
};