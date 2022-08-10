class Solution {
public:
    bool isPowerOfThree(int n) {
        
         if(n == 0 || n == 2){
                   return false;
           }
           if(n == 1){
                   return true;
           }
            
            return (n%3 == 0) && isPowerOfThree(n/3);
        
    }
};