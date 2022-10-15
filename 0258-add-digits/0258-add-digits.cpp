class Solution {
public:
    int addDigits(int num) {
        int total = 0;
        while(num){
            total += num % 10;
            num /= 10;
        }
        if(total/10) return addDigits(total);
        return total;
    }
};