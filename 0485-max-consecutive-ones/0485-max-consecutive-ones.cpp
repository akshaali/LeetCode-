class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN;
        int interCount = 0;
        for(int i = 0; i<nums.size(); i++){
            while(i<nums.size() && nums[i] == 1){
                interCount++;
                i++;
            }
            ans = max(interCount, ans);
            interCount = 0;
        }
        return ans;
        
    }
};