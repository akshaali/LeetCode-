class Solution {
public:
    void helper(vector<string>& ans, int open, int close, string str){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }
        if(close>0) helper(ans, open, close-1, str+")");
        if(open>0) helper(ans, open-1, close+1, str+"(");
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, 0, "");
        return ans;
    }
};