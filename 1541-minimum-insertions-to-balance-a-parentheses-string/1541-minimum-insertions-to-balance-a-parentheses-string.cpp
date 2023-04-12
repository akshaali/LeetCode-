using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int open = 0, close = 0;
        int sz = s.size();
        int res  = 0;
        stack<char> st;
        for(int i = 0; i<sz; i++){
            char ch = s[i];
            if(ch == '('){
               st.push(ch);
            }
            else{
                if(i<sz-1 && s[i+1] == ')'){
                    if(st.size()){
                        st.pop();
                    }else{
                        open++;
                    }
                    i++;
                }else{
                    if(st.size()){
                        st.pop();
                        close++;
                    }else{
                        open++; 
                        close++;
                    }
                }
            }
            // cout<<st.size()<<" "<<open<<" "<<close<<endl;
        }
        // cout<<"final "<<st.size()<<" "<<open<<" "<<close<<endl;
        res = st.size()*2 + close+open;
        return res;
    }
};