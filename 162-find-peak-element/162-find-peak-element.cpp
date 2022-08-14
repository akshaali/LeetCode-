using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         int left = 0, right = nums.size() -1;
//         int size = nums.size();
//         int mid = 0;
//         cout<<nums[1];
//         while(left <= right){
//             mid = (left+right)/2;
//             if((mid==0 || nums[mid]>=nums[mid-1]) && (mid == size-1 || nums[mid]>=nums[mid+1])){
//                 cout<<mid<<endl;
//                 return mid;
//             }
            
//             if(mid == 0){
//                 if(nums[mid]>nums[mid+1]){
//                     return mid;
//                 }
//             }else if(mid == size-1){
//                 if(nums[mid]>nums[mid-1]){
//                     return mid;
//                 }
//             }
//             else if(nums[mid]<nums[mid-1]){
//                 right = mid-1;
//             }else {
//                 left = mid+1;
//             }
//         }
//         return mid;
        
        int low=0,high=nums.size()-1;
        if(nums.size()==1)return 0;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1])return mid;
                else {
                    low=mid+1;
                    continue;
                }
            }
            if(mid==nums.size()-1){
                if(nums[mid]>nums[mid-1])return mid;
                else{
                    high=mid-1;
                    continue;
                }
            }
            
            
   
            if(nums[mid-1]>nums[mid]){
                    high=mid-1;
                }
            else if(nums[mid+1]>nums[mid])low=mid+1;
            else return mid;
         
        }
        return -1;
    }
};