class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        char curr = s[0];
        int currMax = 1;
        for(int i = 1, j = 0; i<s.size(); i++){
            if((s[i] - curr) == 1){
                currMax++;
            }else{
                ans = max(currMax, ans);
                currMax = 1;
            }
            curr = s[i];
        }
        return max(currMax, ans);
    }
};