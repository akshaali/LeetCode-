using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        // double ans = 1;
        // int m = n;
        // n = abs(n);
        // while(n>0){
        //     if(n%2 == 0){
        //         x = x*x;
        //         n /= 2;
        //     }else{
        //         ans = ans*x;
        //         n -= 1;
        //     }
        // }
        // cout<<ans<<endl;
        // return m<0 ? 1/ans : ans;
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};