using namespace std;
class Solution {
public:
    bool areNumbersAscending(string s) {
        int token = -1;
        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                string sub = "";
                while(i<s.size() && isdigit(s[i])){
                    sub += s[i];
                    i++;
                }
                int num = stoi(sub);
                cout<<"token = "<<token<<" s[i] = "<<num<<endl;
                if(token < num){
                    token = num;
                }else {
                    return false;
                }
                sub = "";
            }
            
        }
        cout<<token<<endl;
        return true;
        
    }
};