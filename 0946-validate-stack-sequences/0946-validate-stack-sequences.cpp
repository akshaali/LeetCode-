using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int push = 0, pop = 0;
        while(push<n && pop<n){
            // cout<<"push: "<<push<<" pop: "<<pop<<endl;
            if(st.empty() ||(!st.empty() && st.top() != popped[pop])){
                st.push(pushed[push++]);
            }
            if(!st.empty() && st.top() == popped[pop]){
                st.pop();
                pop++;
            }
        }
        while(push<n)  st.push(pushed[push++]);
        while(pop<n && !st.empty() && st.top() == popped[pop++]) st.pop();
        if(st.empty()) return true;
        return false;
    }
};