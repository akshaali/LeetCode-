class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //O(nlog(n))
        // sort(nums.begin(), nums.end());
        // int min1 = nums[0], min2 = nums[1];
        // int max1 = nums[nums.size() -1], max2 = nums[nums.size()-2];
        // return(max1*max2 - min1*min2);   
        //O(n)
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(auto num : nums){
            if(num>max1){
                max2 = max1; //second greatest
                max1 = num; //first greatest
            }else if(num>max2){
                max2 = num;
            }
            if(num<min1){
                min2 = min1;
                min1 = num;   
            }else if(num<min2){
                min2 = num;
            }
        }
        return(max1*max2 - min1*min2);    
    }
};