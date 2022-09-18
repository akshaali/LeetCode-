using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        // TLE
        // for(int i = 2; i < n ; i++){
        //     if(checkPrime(i)){
        //         cout<<i<<endl;
        //          count++;
        //     }
        // }
        // Sieve of Eratothenes
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i <n; i++ ){
            if(prime[i]){
                count++;
                for(int j = 2*i; j < n; j = j+i){
                    prime[j] = false;
                }
            }
        }
        return count;
    }
    
    bool checkPrime(int n){
        int divisor = 0;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0) {
                divisor++;
            }
            if(divisor>0) return false;
        }
        return true;
    }
};