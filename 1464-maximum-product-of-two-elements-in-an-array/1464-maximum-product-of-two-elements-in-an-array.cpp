using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int max1 = 0, max2 = 0;
        // int i = -1, j = -1;
        // for(int k = 0; k<nums.size(); k++){
        //     if(nums[k]>max1) {
        //         max2 = max1;
        //         max1 = nums[k];
        //         j = i;
        //         i = k;
        //     }
        //     if(nums[k]>max2 && i != k){
        //         max2 = nums[k];
        //         j = k;
        //     }
        // }
        // return (nums[i] - 1)*(nums[j] - 1);
        auto m1 = 0, m2 = 0;
        for (auto n: nums) {
            if (n > m1)
                m2 = exchange(m1, n);
            else
                m2 = max(m2, n);
        }
        return (m1 - 1) * (m2 - 1);
    }
};