using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        int index6 = -1;
        int temp = num;
        int i = 0;
        while(temp>0){
            // cout<<i<<" "<<temp<<" "<<index6<<endl;
            if(temp%10 == 6){
                index6 = i;
            }
            temp /=10;
            i++;
        }
        return index6 > -1 ? num + 3 * pow(10, index6) : num;
    }
};