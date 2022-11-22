using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        nums[0] = nums[0]&1 ? 1: 0;
        for(int i = 1; i<nums.size(); i++){
            nums[i] = (nums[i]&1?1:0) + nums[i-1];   
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            // cout<<nums[i]<<endl;
            if(nums[i] == k) ans++;
            int sum = nums[i] - k;
            if(mp.find(sum)!=mp.end()){
                ans += mp[sum];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};