using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum;
        prefixSum.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){
            int leftSum = prefixSum[i] - nums[i];
            int rightSum = prefixSum.back() - prefixSum[i];
            // cout<<leftSum<<" "<<rightSum<<endl;
            if(leftSum == rightSum) return i;
        }
        return -1;
        
    }
};