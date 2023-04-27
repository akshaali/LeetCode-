class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        int del = 0;
        while(start<end){
            if(s[start]!=s[end]){
                int i1 = start+1, j1 = end, i2 = start, j2=end-1;
                while(i1<j1 && s[i1] == s[j1]){
                    i1++;
                    j1--;
                }
                while(i2<j2 && s[i2] == s[j2]){
                    i2++;
                    j2--;
                }
                return i1>=j1 || i2>=j2;
            }
            start++;
            end--;
        }
        return true;
    }
};