class Solution {
public:
    int minOperations(string s) {
        int ans = 0, sz = s.size();
        for(int i = 0; i<sz; i++){
            ans += (s[i] - '0') == i%2;
        }
        return min(ans, sz - ans);
    }
};