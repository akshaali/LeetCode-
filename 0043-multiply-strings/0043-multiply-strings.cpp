using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
    
        for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
        size_t found = sum.find_first_not_of('0');
        cout<<found<<endl;
        if (found != string::npos){
            return sum.substr(found);
        }
        return "0";
    }
};