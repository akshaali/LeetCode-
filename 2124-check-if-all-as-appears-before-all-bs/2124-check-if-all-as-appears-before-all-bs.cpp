using namespace std;
class Solution {
public:
    bool checkString(string s) {
        for(int i=0; i<s.length()-1; i++){
            bool x = s.substr(i,2) =="ba";
            cout<<" bool valueeeee   "<<s.substr(i,2)<< "     " << x <<endl;
            if(s.substr(i,2) =="ba"){
                return false;
            }
        }
        return true;
        
    }
};