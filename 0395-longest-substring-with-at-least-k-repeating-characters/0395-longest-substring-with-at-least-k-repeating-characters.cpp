class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(mp[s[i]]<k){
               ans = max(longestSubstring(s.substr(0,i), k), longestSubstring(s.substr(i+1, s.size()-i+1), k));
                   return ans;
            }
        }
        return s.size();
    }
};