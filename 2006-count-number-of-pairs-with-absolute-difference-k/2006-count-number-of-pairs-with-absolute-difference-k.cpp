class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int num[101] = {};
        int ans = 0;
        for(auto i: nums) num[i]++;
        for(int i = k+1; i<101;i++){
            ans += (num[i]*num[i-k]);
        }
        return ans;
    }
};