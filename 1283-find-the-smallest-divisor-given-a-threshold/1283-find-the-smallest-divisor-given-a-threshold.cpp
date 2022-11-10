class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        if(nums.size() == threshold) return high;
        while(low<high){
            int mid = low + (high - low)/2;
            if(isValid(nums, mid, threshold)) low = mid+1;
            else high = mid;
        }
        return low;
        
    }
    bool isValid(vector<int> nums, int divisor, int threshold){
        for(auto n: nums){
            threshold -= ceilValue(n, divisor);
            if(threshold<0) return true;
        }
        return false;
    }
    int ceilValue(int a, int b){
        return (a/b + (a%b !=0));
    }
};