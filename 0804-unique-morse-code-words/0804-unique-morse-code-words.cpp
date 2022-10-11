class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string, int> mp;
        for(auto word: words){
            string code;
            for(auto w: word) code += d[w-'a'];
            mp[code]++;
        }
        return mp.size();
    }
};