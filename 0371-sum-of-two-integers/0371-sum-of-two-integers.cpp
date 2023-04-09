using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            
            int temp = (unsigned int)(a&b)<<1;
            cout<<temp<<endl;
            a = a^b;
            b = temp;
        }
        return a;
    }
};