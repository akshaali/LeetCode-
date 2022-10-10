class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int startRow = startPos[0], startCol = startPos[1];
        vector<int> ans;
        int m = s.size();
        for(int i = 0, k = 0; i <m; i++){
            int h = startPos[1], v = startPos[0];
            for(k = i; k<m && min(h,v)>=0 && max(h,v)<n ; k++){
                h += s[k] == 'L' ? -1 : s[k] == 'R' ? 1 : 0;
                v += s[k] == 'U' ? -1 : s[k] == 'D' ? 1: 0;
            }
            ans.push_back(k-i-1 + (min(h,v)>=0 && max(h,v)<n));
        }
        return ans;
        
    }
};