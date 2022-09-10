class Solution {
public:
    int numberOfSteps(int num) {
        // int count = 0;
        // while(num>0){
        //     if(num % 2 == 0){
        //         num /= 2;
        //     }else {
        //         num -= 1;
        //     }
        //     count++;
        // }
        // bit manipulation solution
        if(!num) return 0;
        int res = 0;
        while(num) {
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return res - 1;
        // return count;
        
    }
};