class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixSum;
        prefixSum.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            prefixSum.push_back(prefixSum.back()+ nums[i]);
        }
        int ans = 0;
        for(int i =0; i<nums.size()-1; i++){
            long leftSum = prefixSum[i];
            long rightSum = prefixSum.back() - prefixSum[i];
            if(leftSum>=rightSum) ans++;
        }
        return ans;
        
    }
};