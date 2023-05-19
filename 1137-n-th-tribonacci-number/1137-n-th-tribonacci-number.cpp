class Solution {
public:
    int tribonacci(int n) {
        int prev0 = 0;
        int prev1 = 1;
        int prev2 = 1;
        if(n == 0) return prev0;
        if(n == 1) return prev1;
        if(n == 2) return prev2;
        for(int i = 3; i<=n ; i++){
            int curr = prev0+ prev1 + prev2;
            prev0 = prev1;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};