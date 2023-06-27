using namespace std;
class Solution {
public:
    int n;
    int mod = 1e9+7;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int solve(int index,string& pressedKeys, vector<int>& dp){
        // cout<<"index: "<<index<<endl;
        if(index>=n) return 1;
        if(dp[index] != -1) return dp[index];
        int number = pressedKeys[index] - '0';
        string value = mapping[number];
        int res = 0;
        for(int i = 1; i<value.size() && index+i<n && pressedKeys[i+index] == pressedKeys[index]; i++){
            res = (res%mod + (solve(index+i+1, pressedKeys, dp)%mod))%mod;
        }
        res = (res%mod + (solve(index+1, pressedKeys, dp)%mod))%mod;
        dp[index] = res%mod;
        return res%mod;
    }
    int countTexts(string pressedKeys) {
        n = pressedKeys.size();
        vector<int>dp(n, -1);
        return solve(0, pressedKeys, dp);
    }
};