class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>prev(n2+1,0), curr(n2+1, 0);
        int ans = 0;
        for(int i1 = 1; i1<=n1; i1++){
            for(int i2 = 1; i2<=n2; i2++){
                if(nums1[i1-1] == nums2[i2-1]){
                    curr[i2] = 1 + prev[i2-1];
                    ans = max(curr[i2], ans);
                }else{
                    curr[i2] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};