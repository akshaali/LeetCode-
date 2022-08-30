class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = int(t.back());
        for(int i = 0; i<s.size(); i++){
            res = res^(int(s[i]))^(int(t[i]));
        }
        char res1 = res;
        return res1;
    }
};