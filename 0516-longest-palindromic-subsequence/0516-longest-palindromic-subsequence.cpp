class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=n; i2++){
                if(s1[i1-1] == s[i2-1]){
                    curr[i2] = 1+ prev[i2-1];
                }else{
                    curr[i2] = max(prev[i2], curr[i2-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};