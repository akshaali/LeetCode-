class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int farthestReachSoFar = 0;
        int currIntervalEnd = 0;
        for(int i = 0; i<n-1; i++){
            farthestReachSoFar = max(farthestReachSoFar, i+nums[i]);
            if(i == currIntervalEnd){
                jumps++;
                currIntervalEnd = farthestReachSoFar;
            }
        }
        return jumps;
    }
};