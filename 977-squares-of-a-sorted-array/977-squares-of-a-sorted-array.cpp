class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector <int> arr(n,0);
        int indez = 0;
        for(int i = 0; i<n; i++){
            
            if(nums[i] >= 0) break;
            indez++;
        }
        int i = 0;
        int a = indez-1;
        int b = indez;
        
        if(n<=1){
            nums[0] *= nums[0];
            return nums;
        }
    
        while(b<n && a>=0){
            if(abs(nums[a])<=nums[b]){
                arr[i++] = nums[a] * nums[a--];
            }
            else{
                arr[i++] = nums[b] * nums[b++];
            }
        }
        while(b<n){
            arr[i++] = nums[b] * nums[b++];
        }
        while(a>=0){
            arr[i++] = nums[a] * nums[a--];
        }
        return arr;
        
    }
};