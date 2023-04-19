class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<int> open;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                open.push(res.length());
            }else if(s[i] == ')'){
                int j = open.top();
                open.pop();
                reverse(res.begin()+j, res.end());
            }else{
                res += s[i];
            }
        }
        return res;
    }
};