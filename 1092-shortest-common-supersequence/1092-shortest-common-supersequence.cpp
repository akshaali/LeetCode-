class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        
        for(int i1 = 1; i1<=n1; i1++){
            for(int i2 = 1; i2<=n2; i2++){
                if(text1[i1-1] == text2[i2-1]){
                    dp[i1][i2] = 1+ dp[i1-1][i2-1];
                }else{
                    dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
                }
            }
        }
        
        string ans = "";
        int i1 = n1, i2 = n2;
        while(i1>0 && i2>0){
            if(text1[i1-1] == text2[i2-1]){
                ans += text1[i1-1];
                i1--;
                i2--;
            }else if(dp[i1-1][i2]>dp[i1][i2-1]){
                ans += text1[i1-1];
                i1--;
            }else{
                ans += text2[i2-1];
                i2--;
            }
        }
        while(i1>0){
            ans += text1[i1-1];
            i1--;
        }
        while(i2>0){
            ans += text2[i2-1];
            i2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};