class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 0 || n == 2 || n == 3){
                   return false;
           }
           if(n == 1){
                   return true;
           }
            
            return (n%4 == 0) && isPowerOfFour(n/4);
        
        
    }
};