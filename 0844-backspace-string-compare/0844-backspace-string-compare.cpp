class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> ts;
        for(auto i : s){
            if(i == '#' && !ss.empty()){
                ss.pop();
            }else if(i != '#'){
                ss.push(i);
            }
        }
        for(auto i : t){
            if(i == '#'&& !ts.empty()){
                ts.pop();
            }else if (i != '#'){
                ts.push(i);
            }
        }
        return ss == ts;
    }
};