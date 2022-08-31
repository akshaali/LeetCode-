class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start =0, end = 0, sum = 0;
        int size = nums.size();
        int count = INT_MAX;
        while(end<size){
            while(sum<target && end<size){
                sum += nums[end];
                end++;
            }
            while(sum>=target){
                count = min(count, end-start);
                sum -= nums[start];
                start++;
            }
        }
        if(count ==INT_MAX) return 0;
        return count; 
    }
};