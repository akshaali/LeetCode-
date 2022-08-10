class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 0;
        int copyN = n; 
        if(n == 0){
            return 1;
        }
        while(n!=0){
            int lastBit = n&1;
            mask = (mask <<1) | 1;
            n = n >>1;
        }
        return (mask ^ copyN);
        
    }
};