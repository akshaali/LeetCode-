class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto num: nums) mp[num]++;
        for(auto val : mp){
            if(k == 0){
                ans +=  val.second>1? 1: 0;
            }
            else if(mp.count(val.first+k)) ans++;
        }
        return ans;
    }
};