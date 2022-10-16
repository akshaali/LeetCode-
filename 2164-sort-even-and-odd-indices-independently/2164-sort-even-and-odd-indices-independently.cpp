class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int>maxh;
        priority_queue<int,vector<int>,greater<int>>minh;
        
        for(int i=0;i<size(nums);i++)
            i%2==0?minh.push(nums[i]):maxh.push(nums[i]);
        
        for(int i=0;i<size(nums);i++)
            if(i%2==0)nums[i]=minh.top(),minh.pop();
            else nums[i]=maxh.top(),maxh.pop();
        
        return nums;
    }
};