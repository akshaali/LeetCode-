class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int pt1 = 0;
        int pt2 = 0;
        int zero = 0;
        int n = nums.size();
        int currSize = 0;
        int maxSize = 0;
        while(pt1<n && pt2<n){
            if(nums[pt2] == 0) zero++;
            while(zero>1 && pt1<n){
                if(nums[pt1] == 0){
                    zero--;
                }
                pt1++;
            }
            maxSize = max(maxSize, pt2-pt1+1);
            pt2++;
            
        }
        return maxSize-1;
    }
};