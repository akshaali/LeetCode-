using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int k =-1, size = nums.size();
        for(int i =0; i<size-1; i++){
            if(nums[i]>nums[i+1]){
                k = i+1;
                break;
            }
        }
        if(k==-1){
            return true;
        }
        reverse(nums, 0, k-1);
        reverse(nums, k, size-1);
        reverse(nums, 0, size-1);
        for(int i =0; i<size-1; i++){
            if(nums[i]>nums[i+1]){
               return false;
            }
        }
        return true;
    }
    void reverse(vector<int>& nums, int i, int j){
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};