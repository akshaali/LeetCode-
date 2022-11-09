using namespace std;
class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int mod = 1e9+7;
        int n = s.size();
        int i = 0;
        while(i<n){
            int cnt = 1;
            int j = i;
            ans = ( (ans +cnt) % mod);
            while(j<n && s[++j] == s[i]){
                cnt++;
               ans = ( (ans +cnt) % mod);
            }
            // ans += ((cnt*(cnt+1))/2)%mod;
            i = j;
            // cout<<i<<" "<<j<<endl;
        }
        return ans;
        
    }
};