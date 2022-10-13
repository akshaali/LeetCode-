class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for(auto ch:s){
            freq[ch]++;
        }
        int occ = freq[s[0]];
        for(auto oc: freq){
            if(oc.second != occ) return false;
        }
        return true;
    }
};