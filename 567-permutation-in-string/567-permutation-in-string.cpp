class Solution {
private:
    bool checkIfEqual(int a[26], int b[26]){
        for(int i =0; i<26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int counts1[26] = {0};
        for(auto ch: s1){
            counts1[ch-'a'] +=1;
        }
        int counts2[26] = {0};
        int i = 0;
        int windowSize = s1.size();
        while(i<s2.length() && i<windowSize){
            counts2[s2[i]-'a'] +=1;
            i++;
        }
        if(checkIfEqual(counts1, counts2)){
            return true;
        }
        while(i<s2.length()){
            counts2[s2[i] -'a']++;
            char oldChar = s2[i-windowSize];
            counts2[oldChar-'a']--;
            if(checkIfEqual(counts1, counts2)){
                return true;
            }
            i++;
        }
        return false;
    }
};