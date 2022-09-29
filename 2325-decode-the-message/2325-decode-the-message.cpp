using namespace std;
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map <char, char> decode;
        int alpha = 97;
        for(auto i: key){
            if(i != ' ' && !decode.count(i)){
              decode[i] = alpha;
                alpha++;
            }
        }
        for(auto i: decode){
            cout<<i.first<<" "<<i.second<<endl;
        }
        string res = "";
        for(auto i: message){
            if(i == ' '){
            res += " ";
        }else {
            res += decode[i];
        }
        }
         return res;
        
    }
};