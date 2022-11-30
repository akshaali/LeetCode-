class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<char> st;
        for(auto ch: s){
            if(ch == '('){
                st.push(ans);
                ans = 0;
            }else{
                ans = st.top() + max(ans*2, 1);
                st.pop();
            }
        }
        return ans;
        
    }
};