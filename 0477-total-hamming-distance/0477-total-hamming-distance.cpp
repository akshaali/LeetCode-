class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i<32; i++){
            int bitCount = 0;
            for(int j = 0; j<nums.size(); j++){
                bitCount += ((nums[j]>>i)&1);
            }
            distance += bitCount*(nums.size()-bitCount);
        }
        return distance;
    }
};