class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftcount = 0;
        while(left!=right) {
            left>>=1;
            right>>=1;
            shiftcount++;
        }
        return left<<shiftcount;
    }
};