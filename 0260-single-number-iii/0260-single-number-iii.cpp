class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned long long x_xor_y = 0;
        for(auto n: nums) x_xor_y ^=n;
        unsigned long long right_most_set_bit = x_xor_y & -x_xor_y;
        int x = 0;
        int y = 0;
        for(auto n: nums){
            if((n & right_most_set_bit)) x ^=n;
            else y ^=n;
        }
        vector<int> ans{{x,y}};
        return ans;
    }
};