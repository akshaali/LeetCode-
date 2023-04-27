class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        //Prefix multipication
        int mul = 1;
        for(int i = 0; i<n-1; i++){
            mul *= nums[i];
            ans[i+1] = mul;
        }
        mul = 1;
        for(int i = n-1; i>0; i--){
            mul *= nums[i];
            ans[i-1] *= mul;
        }
        return ans;
        
    }
};