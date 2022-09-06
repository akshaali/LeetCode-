class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        //solution 1
        int size = nums.size();
        // vector<int> out(size);
        // for(int i = 0; i<size;i++){
        //   out[(i+k)%size] = nums[i];
        // }
        // nums = out;
         
        // solution 2
        k = k % size;
        reverse(nums, 0, size-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, size-1);
         
    }
    
    void reverse(vector<int>& nums, int i, int j) {
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
};