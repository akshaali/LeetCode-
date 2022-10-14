using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> pri;
        string ans = "";
        int leftP = 0, rightP = 0;
        int j = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                leftP++;
            }else if(s[i] == ')'){
                rightP++;
            }
            if(leftP == rightP){
                cout<<s.substr(j,i-j+1)<<endl;
                pri.push_back(s.substr(j,i-j+1));
                j = i +1;
            }
        }
        for(auto i: pri){
            cout<<i<<endl;
            ans += i.substr(1,i.size()-2);
        }
        return ans;
    }
};