class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //sorting
        sort(nums.begin(), nums.end());
        int ans = 0;
        int size = nums.size();
        for(int i = 0; i<size/2; i++){
            ans = max(ans , nums[i] + nums[size-i-1]);
        }
        return ans;
        
    }
};