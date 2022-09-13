using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        int n = chars.size();
        int count = 1;
        for(int i = 0; i< n; i++){
            if(i+1<n && chars[i] == chars[i+1]){
                count++;
            }else{
                s.push_back(chars[i]);
                if(count>1){
                    string str = to_string(count);
                    cout<<str<<endl;
                    for(auto ch: str){
                        cout<<ch<<endl;
                        s.push_back(ch);
                    }
                }
                
                count = 1;
            }
        }
        chars = s;
        return s.size();
        
    }
};