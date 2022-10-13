class Solution {
public:
    int commonFactors(int a, int b) {
        int hi = gcd(a,b);
       int ans = 1;
        for(int i = 2; i<=hi; i++){
            ans += ((a%i == 0) && (b%i == 0));
        }
        return ans;
    }
    int gcd(int a, int b){
        if(b == 0) return a;
        if(a == 0) return b;
       if(a>b) return gcd(a%b, b);
        return gcd(a, b%a);
    }
};