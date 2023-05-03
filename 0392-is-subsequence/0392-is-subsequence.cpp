class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tSize = t.size(), sSize = s.size();
        int i = 0, j = 0;
        while(i<tSize && j<sSize){
            if(s[j] == t[i]){
                j++;
            }
            i++;
        }
        return j == sSize;
    }
};