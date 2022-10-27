using namespace std;
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if(num1 == num2) return num1;
        int ans = 0;
        int bitCount = __builtin_popcount(num2);
        // cout<<"bitCount "<<bitCount<<endl;
        
        //seting MSB of ans as per num1
        for(int i = 31; i>=0; i--){
            int currSetbit = (num1 >> i) & 1;
            if(bitCount == 0) return ans;
            if(currSetbit && bitCount>0){
                ans |= (1<<i);
                bitCount--;
            }
        }
        // cout<<"ans "<<ans<<" bitCount "<<bitCount<<endl;
        
        //seting LSB of ans if set bits are still remaning
        for(int i = 0; i<32; i++){
            int currSetBit = (ans>>i)&1;
            if(bitCount == 0) break;
            if(currSetBit == 0){
                ans |= (1<<i);
                bitCount--;
            }
        }
        return ans;   
    }
};