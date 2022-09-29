class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int indexPos = 0, indexNeg = 1;
        int n = nums.size();
        vector<int> ans(n);
        for(auto i: nums){
            if(i<0){
                ans[indexNeg] = i;
                indexNeg +=2;
            }else{
                ans[indexPos] = i;
                indexPos +=2;
            }
        }
        return ans;
    }
};