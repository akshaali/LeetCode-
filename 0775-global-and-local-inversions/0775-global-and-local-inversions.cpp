class Solution {
public:
    int localInversion(vector<int>& nums){
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i-1]>nums[i])ans++;
        }
        return ans;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int cmax = 0, n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            cmax = max(cmax, nums[i]);
            if (cmax > nums[i + 2]) return false;
        }
        return true;
    }
};