using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int maxi = n-1;
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
         // cout<<"i: "<<i<<endl;
        if(i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = n-1;
        while(j>0 && nums[j]<=nums[i]) j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
       
    }
};