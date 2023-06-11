class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long long int>ugly(n, 0);
        ugly[0] = 1;
        vector<int>pt(m, 0);
       for(int i=1;i<n;++i){
           long long int ele = INT_MAX;
           for(int j = 0; j<m; j++){
               long long int prod = ugly[pt[j]]*primes[j];
               ele = min(ele, prod);
           }
           ugly[i] =ele;
           for(int j = 0; j<m; j++){
               if((long long)ugly[pt[j]]*primes[j] == ele) pt[j]++;
           }
        }
        return ugly[n-1];
        
    }
};