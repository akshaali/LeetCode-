class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(auto ch: s){
            int digits = digitSum(ch - 'a' + 1);
            ans += digits;
        }
        while(k>1){
            ans = digitSum(ans);
            k--;
        }
        return ans;
    }
    int digitSum(int n){
        int ans = 0;
        while(n){
            ans += (n%10);
            n /=10;
        }
        return ans;
    }
};