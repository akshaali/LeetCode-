using namespace std;
class Solution {
public:
    bool parse_not(string exp, int &i){
        i = i+2;
        bool res = parse(exp, i);
        i++;
        return !res;
        
    }
    bool parse_and(string exp, int &i){
        i = i+2;
        bool res = parse(exp, i);
        while(exp[i] != ')'){
            i++;
            res = res & parse(exp, i);
        }
        i++;
        // cout<<"and: "<<"i: "<<i<<" res: "<<res<<endl;
        return res;
    }
    bool parse_or(string exp, int &i){
        i = i+2;
        bool res = parse(exp, i);
        // cout<<"orrr: "<<"i: "<<i<<" res: "<<res<<endl;
        while(exp[i] != ')'){
            i++;
            res = res | parse(exp, i);
        }
        // i+=2;
        // bool ret = false;
        // ret |= f(s,i);
        // while(s[i]!=')'){
        //     i++;
        //     ret |= f(s,i);
        // }
        i++;
        // cout<<"or: "<<"i: "<<i<<" res: "<<res<<endl;
        return res;
    }
    bool parse(string exp, int &i){
       if(exp[i] == 'f'){
           i++;
           // cout<<"falseee "<<i<<endl;
           return false;
       }else if(exp[i] == 't'){
           i++;
            // cout<<"falseee "<<i<<endl;
           return true;
       }else if(exp[i] == '&'){
           return parse_and(exp, i);
       }else if(exp[i] == '|'){
           return parse_or(exp, i);
       }
        return parse_not(exp, i);
    }
    bool parseBoolExpr(string exp) {
        int i = 0;
        auto ans = parse(exp, i);
        // cout<<"ans: "<<ans<<endl;
        return ans;
    }
};