class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i<s.size(); i++){
           int c = s[i];
            if(c>=65 &&  c<=90){
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};