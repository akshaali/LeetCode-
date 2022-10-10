class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        stack<string> brackets;
        for(auto ele:s){
            if(ele == '('){
                brackets.push("(");
            }else if(ele == ')'){
                int size = brackets.size();
                maxDepth = max(maxDepth, size);
                brackets.pop();
            }
        }
        return maxDepth;
        
    }
};