using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        // solution 1
        // vector<char> s;
        // int n = chars.size();
        // int count = 1;
        // for(int i = 0; i< n; i++){
        //     if(i+1<n && chars[i] == chars[i+1]){
        //         count++;
        //     }else{
        //         s.push_back(chars[i]);
        //         if(count>1){
        //             string str = to_string(count);
        //             cout<<str<<endl;
        //             for(auto ch: str){
        //                 cout<<ch<<endl;
        //                 s.push_back(ch);
        //             }
        //         }
        //         count = 1;
        //     }
        // }
        // chars = s;
        // return s.size();
        
        // solution 2
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n){
            int j = i+1;
            while(j< n && chars[j] == chars[i]){
                j++;
            }
            chars[ansIndex++] = chars[i];
            int count = j - i;
            if(count>1){
                string cnt = to_string(count);
                for(auto ch: cnt){
                    chars[ansIndex++] = ch;
                }
            }
            i = j ;
        }
        return ansIndex;
    }
};