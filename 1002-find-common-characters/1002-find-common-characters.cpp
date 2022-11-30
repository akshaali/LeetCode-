class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>count(26, INT_MAX);
        vector<string> ans;
         for(int i = 0; i<words.size(); i++){
             vector<int> countEach(26, 0);
             for(auto ch: words[i]){
                 ++countEach[ch-'a'];
             }
             for(int j = 0; j<26; j++){
                 count[j] = min(count[j], countEach[j]);
             }
         }
        for(int i = 0; i<26; i++){
            for(int j = 0; j<count[i]; j++) ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};