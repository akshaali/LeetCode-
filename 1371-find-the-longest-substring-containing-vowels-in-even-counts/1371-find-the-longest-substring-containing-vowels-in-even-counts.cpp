class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> mp;
        mp = {{'a', 1}, {'e', 2}, {'i', 4}, {'o',8}, {'u', 16}};
        vector<int> bitmap(32, -1);
        int longest = 0;
        int mask = 0;
        for(int i = 0; i<s.size(); i++){
            mask ^=mp[s[i]];
            if(mask != 0 && bitmap[mask] == -1){
                bitmap[mask] = i;
            }
            longest = max(longest, i-bitmap[mask]);
        }
        return longest;
    }
};