using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 0;
        while(i<32){
            int bit = (n>>i)&1;
            ans = ans << 1;
            ans = ans | bit;
            i++;
        }
        return ans;
    }
};