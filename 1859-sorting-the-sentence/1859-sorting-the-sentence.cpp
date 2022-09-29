using namespace std;
class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10, "");
        for(int i = 0; i<s.length(); i++){
            string temp = "";
            int j = i;
                while(!isdigit(s[j])){
                    temp += s[j];
                    j++;
                }
            words[s[j]-'0'] = temp;
            cout<<temp<<endl;
            i = j+1;
        }
        string ans;
        for(int i=1; i<10; i++){
            if(words[i].length()>0){
                cout<<words[i]<<endl;
                ans += words[i]+" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};