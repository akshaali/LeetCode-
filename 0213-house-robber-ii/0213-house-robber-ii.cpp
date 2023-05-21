class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = nums[start];
        for(int i = start+1; i<=end; i++){
            int curr = max(prev2, nums[i] + prev1);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return nums[0];
        int ans = max(solve(nums, 0, n-2), solve(nums, 1, n-1));
        return ans;
    }
};