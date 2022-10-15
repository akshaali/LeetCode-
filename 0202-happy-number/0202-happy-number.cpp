class Solution {
public:
    // bool isHappy(int n) {
    //     //wrong - 403/404
    //     int total = 0;
    //     while(n){
    //         int sq = n %10;
    //         total += (sq *sq);
    //         n /= 10;
    //     }
    //     if(total == 1) return true;
    //     if((total*total)/10) return isHappy(total);
    //     return false;
    // }
    int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};