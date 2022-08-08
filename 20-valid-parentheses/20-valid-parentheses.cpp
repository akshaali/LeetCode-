class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0){
            return false;
        }
        vector<char> leftSymbol;
        for(int i = 0; i <s.size(); i++){
          if(s[i] == '(' || s[i] =='[' || s[i] == '{'){
              leftSymbol.push_back(s[i]);
          }else if(
(s[i] == ')' && leftSymbol.size() != 0 && leftSymbol[leftSymbol.size() -1] =='(') ||
(s[i] == ']' && leftSymbol.size() != 0 && leftSymbol[leftSymbol.size() -1] =='[') ||
(s[i] == '}' && leftSymbol.size() != 0 && leftSymbol[leftSymbol.size() -1] =='{')
          ){
            leftSymbol.pop_back();
          }else{
              return false;
          }
        
    }
        return !leftSymbol.size();
};
             };
             