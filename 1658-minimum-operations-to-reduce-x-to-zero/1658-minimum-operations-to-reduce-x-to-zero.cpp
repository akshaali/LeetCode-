using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        mp[0] = -1;
        mp[nums[0]] = 0;
        int n = nums.size();
        for(int i =1; i<n; i++){
            nums[i] += nums[i-1];
            mp[nums[i]] = i;
        }
        if(x>nums[n-1]) return -1;
        int target = nums[n-1] - x;
        for(int i = 0; i<n; i++){
            int targetSum = nums[i] - target;
            // cout<<"targetSum: "<<targetSum<<" "<<mp.count(targetSum)<<endl;
            if(mp.count(targetSum)){
                int length = i-mp[targetSum];
                // cout<<length<<endl;
                ans = min(ans, n - length);
            }
        }
        return ans == INT_MAX ? -1: ans;
        
    }
};