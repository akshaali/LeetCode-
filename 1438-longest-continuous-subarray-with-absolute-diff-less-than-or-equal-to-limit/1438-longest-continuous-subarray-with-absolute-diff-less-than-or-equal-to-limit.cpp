class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int pt1 = 0, pt2 = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        deque<int> minD; //monotonic increasing deque
        deque<int> maxD; //monotonic decreasing deque 
        for(;pt2<nums.size(); pt2++){
            while(!minD.empty() && nums[pt2]<nums[minD.back()]){
                minD.pop_back();
            }
            while(!maxD.empty() && nums[pt2]>nums[maxD.back()]){
                maxD.pop_back();
            }
            minD.push_back(pt2);
            maxD.push_back(pt2);
            while(nums[maxD.front()] - nums[minD.front()] > limit){
                pt1++;
                if(pt1>minD.front()) minD.pop_front();
                if(pt1>maxD.front()) maxD.pop_front();
            }
            ans = max(ans, pt2 - pt1 + 1);
        }
        return ans;
    }
};