class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int>> work;
        for(auto log: logs){
            work[log[0]].insert(log[1]);
        }
        for(auto val: work){
            ++ans[val.second.size() - 1];
        }
        return ans;
    }
};