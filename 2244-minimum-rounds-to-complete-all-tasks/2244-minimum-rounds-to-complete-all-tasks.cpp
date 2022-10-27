class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto n: tasks) mp[n]++;
        int ans = 0;
        for(auto item: mp){
            if(item.second <2)return -1;
            ans += (item.second + 2) /3;
        }
        return ans;
    }
};