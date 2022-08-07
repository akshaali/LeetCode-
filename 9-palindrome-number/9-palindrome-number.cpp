class Solution {
public:
    bool isPalindrome(int x) {
            unsigned long long int sum = 0,copy = x;
            int b;
            while(copy>0){
                b = copy % 10;
                sum = sum *10 + b;
                copy = copy/10;
            }
            return sum == x;
    }
};