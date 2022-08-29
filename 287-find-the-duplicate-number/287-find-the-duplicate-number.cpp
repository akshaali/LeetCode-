class Solution {
public:
    int findDuplicate(vector<int>& arr) {
//        int low = 1, high = nums.size() - 1, cnt;
//         while(low <=  high)
//         {
//             int mid = low + (high - low) / 2;
//             cnt = 0;
//             // cnt number less than equal to mid
//             for(int n : nums)
//             {
//                 if(n <= mid)
//                     ++cnt;
//             }
//             // binary search on left
//             if(cnt <= mid)
//                 low = mid + 1;
//             else
//             // binary search on right
//                 high = mid - 1;
            
//         }
//         return low;
         for(int i=0;i<arr.size();i++){
        
        // finding first negative elemnet
        if(arr[abs(arr[i])-1]<0)return abs(arr[i]);
        
		// if the number is positive make it negative
        else arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
                   
    }
    return 0;
        
    }
       
};