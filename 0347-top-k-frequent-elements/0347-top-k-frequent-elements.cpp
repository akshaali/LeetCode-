//Bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        vector<vector<int>>freq(n+1);
        vector<int>ans;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }
        for(int i = n; i>=0; i--){
            for(auto n: freq[i]){
                ans.push_back(n);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};