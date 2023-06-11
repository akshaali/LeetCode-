class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n+1, 0);
        ugly[1] = 1;
        int p2=1;
        int p3=1;
        int p5=1;
       for(int i=2;i<=n;++i){
            int el = min({ugly[p2]*2, ugly[p3]*3, ugly[p5]*5});
            ugly[i] =el;
            if( ugly[p2]*2==el) p2++;
            if( ugly[p3]*3==el) p3++;
            if( ugly[p5]*5==el) p5++;
        }
        return ugly[n];
    }
};