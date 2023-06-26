using namespace std;
class Solution {
public:
    int length = 0;
    int startIndex = 0;

    bool solve(int start, int end, string &str, vector<vector<int>>&dp){
        if(start >= end) return true;
        if(dp[start][end] != -1) return dp[start][end];
        if(str[start] == str[end] && solve(start+1, end-1, str, dp)){
            int currLen = end - start + 1;
            if(currLen>length){
                length = currLen;
                startIndex = start;
            }
            dp[start][end] = true;
            return true;
        }
        solve(start+1, end, str,dp);
        solve(start, end-1, str,dp);
        dp[start][end] = false;
        return false;
    }
    string longestPalindrome(string str) {
        int n = str.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        solve(0, n-1, str,dp);
        string res = "";
        if(length == 0) res += str[0];
        else res = str.substr(startIndex, length);
        return res;
    }
};