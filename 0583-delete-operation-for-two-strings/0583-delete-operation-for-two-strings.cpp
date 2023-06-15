class Solution {
public:
    int n1, n2;
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(n2+1, 0), curr(n2+1);
        for(int i1 = 1; i1<=n1; i1++){
            for(int i2 = 1; i2<=n2; i2++){
                if(text1[i1-1] == text2[i2-1]){
                    curr[i2] = 1+ prev[i2-1];
                }else{
                    curr[i2] = max(prev[i2], curr[i2-1]);
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
    int minDistance(string word1, string word2) {
        n1 = word1.size();
        n2 = word2.size();
        int longestCommonSubseq = longestCommonSubsequence(word1, word2);
        return n1+n2 - 2*longestCommonSubseq;
    }
};