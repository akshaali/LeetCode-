using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i<tokens.size(); i++){
            string str = tokens[i];
            if(str == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b+a;
                // cout<<c<<endl;
                st.push(c);
                
            }else if(str == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b-a;
                st.push(c);
                
            }else if(str == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b*a;
                st.push(c);
                
            }else if(str == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b/a;
                // cout<<c<<endl;
                st.push(c);
            }else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};