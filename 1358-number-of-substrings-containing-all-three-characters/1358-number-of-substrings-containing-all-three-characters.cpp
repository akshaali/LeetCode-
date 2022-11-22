using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int pt1 = 0, pt2 = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int cnt[3] = {0,0,0};
        int ans = 0;
        for(;pt2<n; pt2++){
            ++cnt[s[pt2]-'a'];
            while(cnt[0] && cnt[1] && cnt[2]){
                --cnt[s[pt1++]-'a'];
            }
            ans += pt1;
        }
        return ans;
    }
};