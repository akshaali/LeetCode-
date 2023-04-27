class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int currSum = nums[i] + nums[left] + nums[right];
                if(currSum == target) return currSum;
                if(abs(target-closest) > abs(target-currSum)){
                    closest = currSum;
                }
                if(currSum<target) left++;
                if(currSum>target) right--;
            }
        }
        return closest;
    }
};