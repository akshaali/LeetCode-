class Solution {
public:
    int mod = 1e9+7;
    long long int modPower(long long int num, long long pow){
        if(pow == 0) return 1;
        if(pow % 2 == 0) return modPower(num%mod*num%mod, pow/2);
        return (num%mod * modPower(num, pow-1)%mod)%mod;
        
    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        if(n%2 == 0) return (modPower(5, n/2)%mod * modPower(4, n/2)%mod)%mod;
        return (modPower(5, n/2+1)%mod * modPower(4, n/2)%mod)%mod;
    }
};