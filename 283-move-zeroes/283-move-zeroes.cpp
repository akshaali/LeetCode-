class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer=0, nonZeroPointer=0, size = nums.size();
        int i = 0;
        while(zeroPointer<size && nonZeroPointer <size){
            if(nums[nonZeroPointer] !=0){
                swap(nums[zeroPointer], nums[nonZeroPointer]);
                zeroPointer++;
               
            }
             nonZeroPointer++;
        }
        
    }
};