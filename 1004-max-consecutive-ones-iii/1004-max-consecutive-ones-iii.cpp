class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int temp_k = 0;
        int ans = 0;
        for(end = 0; end<n; end++){
            if(nums[end] == 0) temp_k++;
            while(temp_k>k){
                if(nums[start] == 0) temp_k--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};