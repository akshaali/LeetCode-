using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(n == 1) return x;
        long N = n;
        if(N<0){
            N = -N;
            x = 1/x;
        }
        if(N%2 == 1){
           return x*myPow(x, (N-1));
        }
        return myPow(x*x, (N/2));
    }
};