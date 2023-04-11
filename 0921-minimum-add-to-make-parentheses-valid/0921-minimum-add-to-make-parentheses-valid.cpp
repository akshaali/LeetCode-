using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else{
                 if(st.size() && st.top() == '('){
                     st.pop();
                 }else{
                     st.push(ch);
                 }
            }
            // cout<<sz<<endl;
        }
        return st.size();
        
    }
};