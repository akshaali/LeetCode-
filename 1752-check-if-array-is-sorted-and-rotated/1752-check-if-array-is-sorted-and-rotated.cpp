using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int k =-1, size = nums.size();
        //solution 1
        // for(int i =0; i<size-1; i++){
        //     if(nums[i]>nums[i+1]){
        //         k = i+1;
        //         break;
        //     }
        // }
        // if(k==-1){
        //     return true;
        // }
        // reverse(nums, 0, k-1);
        // reverse(nums, k, size-1);
        // reverse(nums, 0, size-1);
        // for(int i =0; i<size-1; i++){
        //     if(nums[i]>nums[i+1]){
        //        return false;
        //     }
        // }
        // return true;
        
        
        //solution 2 
        int count = 0;
        for(int i=1;i<size;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[size-1]>nums[0]){
            count++;
        }
        return count<=1;
        
    }
    void reverse(vector<int>& nums, int i, int j){
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};