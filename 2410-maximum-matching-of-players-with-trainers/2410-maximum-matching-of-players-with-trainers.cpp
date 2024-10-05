class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = players.size();
        int m = trainers.size();
        int ans = 0;
        int j = 0;
        for(int i = 0; i<m; i++){
            if(j<n && trainers[i]>=players[j]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};