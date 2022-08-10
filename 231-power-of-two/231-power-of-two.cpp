#include <typeinfo>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // solution 1
        // if(n ==1){
        //     return true;
        // }else if(n%2 != 0 || n == 0 || n <0){
        //     return false;
        // }else{
        //     while(n>2){
        //     n = n/2;
        //     if(n%2 != 0){
        //         return false;
        //     }
        // }
        // }
        // return true;
        
         if(n == 0){
                   return false;
           }
           if(n == 1){
                   return true;
           }
            
            return (n%2 == 0) && isPowerOfTwo(n/2);
        
    }
};