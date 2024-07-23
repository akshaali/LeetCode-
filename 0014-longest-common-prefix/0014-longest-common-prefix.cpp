class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        bool match = true;
       for(int j = 0; j<strs[0].size(); j++){
            for(int i = 1; i<n; i++){
                if(strs[i][j] != strs[0][j]) match = false;
            }
            if(match) ans += strs[0][j];
        }
        return ans;
    }
};