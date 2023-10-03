class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word : words){
            if(helper(word) == helper(pattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
    string helper(string word){
        unordered_map<char, int> mp;
        for(auto ch: word) if(!mp[ch]) mp[ch] = mp.size();
        for(int i = 0; i<word.size(); i++) word[i] = 'a' + mp[word[i]];
        return word;
    }
};