class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = k-1;
        int n = nums.size();
        int ans = INT_MAX;
        while(left<=right && right<n){
            ans = min(ans, nums[right++]-nums[left++]);
        }
        return ans;
    }
};