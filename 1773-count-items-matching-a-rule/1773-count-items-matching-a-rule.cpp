class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        int checkIndex;
        if(ruleKey == "type") checkIndex = 0;
        else if(ruleKey == "color") checkIndex = 1;
        else checkIndex = 2;
        for(auto item: items){
            if(item[checkIndex] == ruleValue) ans++;
        }
        return ans;
        
    }
};