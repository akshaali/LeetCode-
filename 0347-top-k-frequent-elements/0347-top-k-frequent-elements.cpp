using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        vector<vector<int>>list(n);
        vector<int> ans;
        for(int i = 0; i<n; i++){
           mp[nums[i]]++;
        }
        for(auto ele:mp){
            list[ele.second-1].push_back(ele.first);
        }
        for(int i = n-1; i>=0 && ans.size()<k; i--){
                for(int j = 0; j<list[i].size(); j++){
                    ans.push_back(list[i][j]);
                }
            // cout<<list[i].size()<<endl;
        }
        return ans;   
    }
};