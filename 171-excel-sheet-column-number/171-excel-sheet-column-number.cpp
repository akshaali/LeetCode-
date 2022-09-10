using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int out;
        int n = columnTitle.size() -1;
        for(auto ch: columnTitle){
            cout<<"character: "<<ch<<" value of n: "<<n<<endl;
            int charVal = ch - 64;
            int power26 = pow(26, n);
            cout<<"charVal  "<<charVal<<endl;
            out += charVal*power26;
            cout<<"out values: "<<out<<" power value: "<<pow(26, n)<<endl;
            n--;
        }
        return out;
    }
};