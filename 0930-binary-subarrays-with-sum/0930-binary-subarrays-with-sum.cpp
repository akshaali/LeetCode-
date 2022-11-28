using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //prefix sum
        for(int i = 1; i< nums.size(); i++){
            nums[i] += nums[i-1];
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            // cout<<nums[i]<<endl;
            if(nums[i] == goal) ans++;
            int sum = nums[i] - goal;
            if(mp.find(sum) != mp.end()){
                // cout<<"sum: "<<sum<<" mp[sum]: "<<mp[sum]<<endl;
                ans += mp[sum];
            };
            // cout<<"ans: "<<ans<<endl;
            mp[nums[i]]++;
        }
        return ans;
    }
};