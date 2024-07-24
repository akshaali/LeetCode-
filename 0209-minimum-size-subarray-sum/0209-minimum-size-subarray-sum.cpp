class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int min_len = INT_MAX;
        int sum = 0;
        while(end<n){
            while(end<n && sum<target){
                sum += nums[end++];
            }
            // cout<<"sum1: "<<sum<<" end1: "<<end<<endl;
            while(sum>=target && start<n){
                min_len = min(min_len, end - start);
                sum -= nums[start++];
            }
            // cout<<"sum1: "<<sum<<" end1: "<<end<<" start: "<<start<<endl;
        }
        return min_len == INT_MAX ? 0: min_len;
    }
};