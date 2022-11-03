class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int>prefixSum;
        prefixSum.push_back(nums[0]);
        for(int i =1; i<nums.size(); i++){
            prefixSum.push_back(prefixSum.back()+nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){
            int mid = i;
            int leftSum = mid==0 ? 0 : prefixSum[i-1];
            int rightSum = mid == nums.size() - 1 ? 0 : prefixSum.back() - prefixSum[i];
            if(leftSum == rightSum) return mid;
        }
        return -1;
        
    }
};