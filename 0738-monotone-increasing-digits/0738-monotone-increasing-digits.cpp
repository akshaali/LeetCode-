using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<=9) return n;
        string strn = to_string(n);
        int monotoneIdx;
        for(int i=strn.size()-1; i>0; i--){
            if(strn[i]<strn[i-1]){
                monotoneIdx = i-1;
                strn[i-1]--;
            }
        }
        cout<<monotoneIdx<<endl;
        for(int i = monotoneIdx + 1; i<strn.size(); i++){
            strn[i] = '9';
        }
        
        return stoi(strn);
    }
};