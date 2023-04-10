using namespace std;
class Solution {
private:
    bool matches(char top, char brac){
        if(top == '{' && brac == '}') return true;
        else if(top == '[' && brac == ']') return true;
        else if(top == '(' && brac == ')') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '{' || ch == '[' || ch == '('){
                st.push(ch);
            }else{
                // cout<< st.top()<<" "<<ch<<endl;
                if(!st.empty()){
                    if(matches(st.top(), ch)){
                        // cout<<"innn"<<endl;
                        st.pop();
                    }else return false;
                }else return false;
            }
        }
        return st.empty() ? true : false;
    }
};