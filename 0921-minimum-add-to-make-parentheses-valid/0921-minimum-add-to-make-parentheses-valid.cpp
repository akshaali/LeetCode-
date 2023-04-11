using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        // S.C = o(n)
        // stack<char> st;
        // for(int i = 0; i<s.size(); i++){
        //     char ch = s[i];
        //     if(ch == '('){
        //         st.push(ch);
        //     }
        //     else{
        //          if(st.size() && st.top() == '('){
        //              st.pop();
        //          }else{
        //              st.push(ch);
        //          }
        //     }
        // }
        // return st.size();
        // solution 2
        int open = 0, close = 0;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                open++;
            }
            else{
                 if(open){
                     open--;
                 }else{
                     close++;
                 }
            }
        }
        return open+close;
    }
};