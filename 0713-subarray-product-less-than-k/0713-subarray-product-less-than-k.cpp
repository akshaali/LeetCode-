using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int ans = 0;
        long long prod = 1;
        for(int i = 0, j = 0; i<nums.size(); i++){
            prod *= nums[i];
            while(j<=i && prod>=k){
                prod /=nums[j++];
            }
            // cout<<i<<" "<<j<<" ans: "<<ans<<endl;
            ans +=(i-j+1);
        }
        return ans;
    }
};