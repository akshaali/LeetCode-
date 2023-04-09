class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numberOfZero = 0;
        int numberOfOne = 0;
        int numberOfTwo = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) numberOfZero++;
            else if(nums[i] == 1) numberOfOne++;
            else numberOfTwo++;
        }
        int index = 0;
        while(index<nums.size()){
            if(numberOfZero>0){
                nums[index++] = 0;
                numberOfZero--;
            }else if(numberOfOne>0){
                nums[index++] = 1;
                numberOfOne--;
            }else{
                nums[index++] = 2;
            }
        }
    }
};