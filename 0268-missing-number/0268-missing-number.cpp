using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int num = 0;
        for(int i = 0; i<nums.size(); i++){
            num ^=(nums[i]^(i+1));
        }
        return num;
    }
};