class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        int freq[26] = {};
        unordered_map<int, int> used;
        for(auto ch: s) freq[ch-'a']++;
        for(int i = 0; i<26; i++){
            for(; freq[i] && used[freq[i]]++; --freq[i]){
                ans++;
            }
        }
        return ans;
    }
};