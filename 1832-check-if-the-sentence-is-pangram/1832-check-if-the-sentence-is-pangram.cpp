class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool alpha[26] = {};
        for(auto ch: sentence){
            alpha[ch - 'a'] = true;
        }
        for(auto al: alpha){
            if(!al){
                return false;
            }
        }
        return true;
        
    }
};