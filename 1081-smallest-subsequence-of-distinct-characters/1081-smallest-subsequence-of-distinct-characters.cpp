class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        unordered_map<char,int> s_freq;
        unordered_map<char, bool>seen;
        for(auto ch: s) s_freq[ch]++;
        for(auto ch: s) seen[ch] = false;
        for(auto ch: s){
             s_freq[ch]--;
            if (seen[ch] == true) continue;
            while(ans.size() && s_freq[ans.back()] && ans.back()>ch){
                seen[ans.back()] = false;
                ans.pop_back();
            }
            ans += ch;
            seen[ch] = true;
        }
        return ans;
    }
};