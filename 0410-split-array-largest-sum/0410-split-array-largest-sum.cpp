class Solution {
public:
    int getSubarray(vector<int>& nums, int sum){
        int count = 1;
        int currSum = 0;
        for(int i = 0; i<nums.size(); i++){
            if(currSum + nums[i] <= sum ){
                currSum += nums[i];
            }else {
                count++;
                currSum = nums[i];
            }   
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low + (high-low)/2;
            int subarray = getSubarray(nums, mid);
            // cout<<"mid: "<<mid<<" subarray: "<<subarray<<endl;
            if(subarray>k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};