using namespace std;
class Solution {
public:
    string interpret(string command) {
        unordered_map<string,string>ump;
        ump["G"] ="G";
        ump["()"] = "o";
        ump["(al)"] = "al";
        string res;
        for(int i = 0; i<command.size();i++){
            cout<<"iterator: "<<i<<" value at i : "<<command[i]<<endl;
            if(command[i] == 'G'){
                res += ump["G"];
            }else if(command[i] == '(' && i+1<command.size()){
                if(command[i+1] == ')'){
                    res += ump["()"];
                    i +=1;
                }else{
                     res += ump["(al)"];
                    i +=3;
                }
                
            }
        }
        return res;
    }
};