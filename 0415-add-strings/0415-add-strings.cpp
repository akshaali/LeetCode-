using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int n1 = num1.size(), n2 = num2.size();
        int p1 = n1-1, p2 = n2 -1;
        int carry = 0, intermediate;
        while(p1>=0 && p2>=0){
            intermediate = (num1[p1--] - '0') + (num2[p2--] - '0') + carry;
            ans += to_string((intermediate) % 10);
            carry = intermediate /10;
        }
        while(p1>=0){
            intermediate = num1[p1--]-'0' + carry;
            ans += to_string( (intermediate)%10);
            carry = intermediate/10;
        }
        while(p2>=0){
            // cout<<carry<<endl;
            intermediate = num2[p2--]-'0' + carry;
            ans += to_string( (intermediate)%10);
            carry = intermediate/10;
        }
        if(carry) ans += (carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};