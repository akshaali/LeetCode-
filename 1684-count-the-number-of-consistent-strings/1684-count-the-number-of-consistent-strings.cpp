class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool alpha[26] = {};
        int ans = words.size();
        for(char c: allowed) alpha[c - 'a'] = true;
        for(auto word: words){
            for(auto c: word){
                if(!alpha[c-'a']){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};