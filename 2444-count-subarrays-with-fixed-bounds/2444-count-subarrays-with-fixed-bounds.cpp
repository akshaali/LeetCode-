class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minFound = false, maxFound = false;
        int start = 0, minIndx = 0, maxIndx = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if(nums[i] == minK){
                minFound = true;
                minIndx = i;
            }
            if(nums[i] == maxK){
                maxFound = true;
                maxIndx = i;
            }
            if(minFound && maxFound){
                ans += (min(minIndx, maxIndx) - start + 1);
            }
        }
        return ans;
    }
};