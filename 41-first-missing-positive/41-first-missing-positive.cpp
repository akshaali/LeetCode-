using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // TLE
        // int size = nums.size();
        // long long int max=0;
        // for(int i = 0; i<size; i++){
        //     if(nums[i]>max){
        //         max = nums[i];
        //     }
        // }
        // vector<int> possibilities(max+1);
        // for (int i = 0; i < max+1; i++)
        // {
        //     possibilities[i] = i+1;
        // }
        // for(int i = 0; i<size; i++){
        //     if(nums[i]>0){
        //         possibilities[nums[i]-1] = -possibilities[nums[i]-1];
        //     }
        // }
        //  for (int i = 0; i < max+1; i++){
        //       if(possibilities[i]>0){
        //           return (possibilities[i]);
        //       }
        //  }
        // return size;
        
        // let's try something else 
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i]<0){
                nums[i] = 0;
            }
        }
        
        for(int i = 0; i < size; i++){
            int val = abs(nums[i]);
            if(val>=1 && val<=size){
                if(nums[val-1]>0){
                    nums[val -1] = -1 * nums[val-1];
                }else if(nums[val-1]==0)
                    nums[val-1]=-1*(size+1);
            }
        }
        
        for(int i = 1; i<=size; i++){
            cout << nums[i-1] << '\n';
            
            if(nums[i-1] >=0){
                return i;
            }
        }
        return size+1;
       
    }
};