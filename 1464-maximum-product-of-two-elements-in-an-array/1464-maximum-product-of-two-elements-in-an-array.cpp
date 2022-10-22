using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int i = -1, j = -1;
        for(int k = 0; k<nums.size(); k++){
            // cout<<max2<<" "<<max1<<endl;
            if(nums[k]>max1) {
                max2 = max1;
                max1 = nums[k];
                j = i;
                i = k;
            }
            if(nums[k]>max2 && i != k){
                max2 = nums[k];
                j = k;
            }
        }
        // cout<<i<<" "<<j<<endl;
        // return 0;
        return (nums[i] - 1)*(nums[j] - 1);
    }
};