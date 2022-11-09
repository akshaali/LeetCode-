class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remaning;
        int n = rocks.size();
        for(int i = 0; i<n; i++){
            remaning.push_back(capacity[i] - rocks[i]);
        }
        sort(remaning.begin(), remaning.end());
        int ans = 0;
        for(int i = 0; i<n && additionalRocks>0; i++){
            if(remaning[i] == 0 || remaning[i]<=additionalRocks) ans++;
            additionalRocks -=remaning[i];
        }
        return ans;
    }
};