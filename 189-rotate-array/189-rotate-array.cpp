class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> out(size);
        for(int i = 0; i<size;i++){
          out[(i+k)%size] = nums[i];
        }
        nums = out;
    }
};