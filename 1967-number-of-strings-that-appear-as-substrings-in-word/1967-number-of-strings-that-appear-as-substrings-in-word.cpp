class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto str: patterns){
            if(word.find(str) != -1){
                ans++;
            }
        }
        return ans;   
    }
};