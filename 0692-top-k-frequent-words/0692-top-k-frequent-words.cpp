class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int>mp;
        vector<vector<string>>list(n);
        vector<string> ans;
        for(int i = 0; i<n; i++){
            mp[words[i]]++;
        }
        for(auto ele : mp){
            list[ele.second].push_back(ele.first);
        }
        for(int i = n-1; i>=0 && ans.size()<k; i--){
            sort(list[i].begin(), list[i].end());
            for(int j = 0; j<list[i].size() && ans.size()<k; j++){
                ans.push_back(list[i][j]);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
        
    }
};