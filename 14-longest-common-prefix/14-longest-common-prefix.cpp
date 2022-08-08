#include<algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }else if(strs.size() ==1){
            return strs[0];
        }else {
            sort(strs.begin(), strs.end());
            int min_ = min(strs[0].size(), strs[strs.size() -1].size());
            int i = 0;
            while(i <min_ && strs[0][i] == strs[strs.size() -1][i]){
                i++;
            };
        return strs[0].substr(0, i);
           
    };
}; 
};