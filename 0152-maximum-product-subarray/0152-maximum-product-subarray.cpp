class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 0, maxProd = INT_MIN, suffix = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            prefix = prefix ? prefix*nums[i] : nums[i];
            suffix = suffix ? suffix*nums[n-i-1] : nums[n-i-1];
            maxProd = max(maxProd, max(prefix, suffix));
        }
        return maxProd;
    }
};