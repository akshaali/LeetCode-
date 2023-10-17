using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        double ans = 1;
        long long m = n;
        if(m<0) m = -m;
        cout<<n<<" "<<m<<endl;
        while(m>0){
            if(m%2 == 1){
                ans = ans*x;
                m -= 1;
            }else{
                x = x*x;
                m /= 2;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;
       
       
        
        // double num = 1;
        // long long nn = n;
        // if(nn < 0) nn = -nn;
        // while(nn>0){
        //     if(nn%2==1){
        //         num = num * x;
        //         nn--;
        //     }
        //     else{
        //         x = x*x;
        //         nn/=2;
        //     }
        // }
        // if(n < 0){
        //     num = 1.0/num;
        // }
        // return num;
    }
};