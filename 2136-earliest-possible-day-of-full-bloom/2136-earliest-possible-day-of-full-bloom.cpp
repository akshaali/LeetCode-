using namespace std;
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // for(int i = 1; i< plantTime.size(); i++){
        //     plantTime[i] = plantTime[i] + plantTime[i-1];
        // }
        // int ans = plantTime.back();
        // for(int i = 0; i<plantTime.size(); i++){
        //     ans = max(ans, plantTime[i]+growTime[i]+1);
        // }
        int n = plantTime.size();
        vector<pair<int, int>> store;
        for(int i = 0; i<n; i++){
            store.push_back({growTime[i], plantTime[i]});
        }
        sort(store.begin(), store.end());
        int fullBloom = 0;
        int currBloom = 0;
        for(int i = n-1; i>=0; i--){
            currBloom = currBloom + store[i].second;
            fullBloom = max(fullBloom, store[i].first + currBloom);
            // cout<<store[i].first<<" "<<store[i].second<<endl;
        }
        return fullBloom;
    }
};