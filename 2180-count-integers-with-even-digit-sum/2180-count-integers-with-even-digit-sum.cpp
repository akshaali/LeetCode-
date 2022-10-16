class Solution {
public:
    int countEven(int num) {
        int sum = 0, n = num;
        while(n){
            sum += (n%10);
             n /=10;
        }
        return (sum&1) ? (num-1)/2 : num/2;
    }
};