class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string output;
        int index = 0;
        if(digits.size() == 0) return ans;
        solve(digits, index, output, ans, mapping);
        return ans;
    }
    void solve(string digits, int index, string output, vector<string> &ans, string mapping[]){
        //base case
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(digits, index+1, output, ans, mapping);
            output.pop_back();
        }
    }
};