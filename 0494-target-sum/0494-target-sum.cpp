class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
       int total = 0;
        int n = arr.size();
        target = abs(target);
        for(int i = 0; i<n; i++) total += arr[i];
        if((total+target)%2) return 0;
        int tar = (total+target)/2;
        vector<int>prev(tar+1,0), curr(tar+1,0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0]<=tar) prev[arr[0]] = 1;
        for(int index = 1; index<n; index++){
            for(int sum = 0; sum<=tar; sum++){
                int notTake =prev[sum];
                int take = 0;
                if(arr[index]<=sum){
                    take = prev[sum-arr[index]];
                }
                int ans = (take+notTake);
                curr[sum] = ans;
            }
            prev=curr;
        }

        return prev[tar];
    }
};