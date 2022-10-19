class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int localMax = nums[0], partitionIdx = 0, maxi = localMax;
        for (int i = 1; i < nums.size(); i++)
            if (localMax > nums[i]) {
                localMax = maxi;
                partitionIdx = i;
            } else maxi = max(maxi, nums[i]);
        return partitionIdx + 1;
    }
};