class Solution {
public:
    string truncateSentence(string s, int k) {
        int wordCount = 0, i;
        for(i=0; i<s.size(); i++){
            if(s[i] == ' ' && wordCount<k){
                wordCount++;
            }if(wordCount == k) break;
        }
        return s.substr(0, i);
        
    }
};