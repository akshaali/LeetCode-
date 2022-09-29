using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
         int ele[201] = {};
        int ans = 0;
        for(auto n: nums){
            if(n >= 2 * diff){
                ans += (ele[n-diff] && ele[n-2*diff]);
            }
            ele[n] = true;
        }
        return ans;
    }
};