class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int i1 = 0, i2 = 0;
        string ans = "";
        while(i1<n1 && i2<n2){
            ans += word1[i1++];
            ans += word2[i2++];
        }
        while(i1<n1){
            ans += word1[i1++];
        }
        while(i2<n2){
            ans += word2[i2++];
        }
        return ans;
    }
};