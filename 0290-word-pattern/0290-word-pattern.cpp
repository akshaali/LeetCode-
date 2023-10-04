using namespace std;
class Solution {
public:
    vector<string> split(string str, char del){
        string temp = "";
        vector<string> ans;
        for(int i=0; i<str.size(); i++){
            if(str[i] != del){
                temp += str[i];
            }
            else{
                ans.push_back(temp);
                temp = "";
            }
        }
        ans.push_back(temp);
        return ans;
    }
    
    string helper1(string pattern){
        unordered_map<char, int> mp;
        string ans = "";
        for(auto ch: pattern){
            if(!mp[ch]){
                mp[ch] = mp.size();
            }
        }
        for(int i = 0; i<pattern.size(); i++){
            ans += 'a' + mp[pattern[i]];
        }
        return ans;
    }
    
    string helper2(vector<string>& arr){
        unordered_map<string, int> mp;
        string ans = "";
        for(auto str: arr){
            if(!mp[str]){
                mp[str] = mp.size();
            }
        }
        for(int i = 0; i<arr.size(); i++){
            ans += 'a' + mp[arr[i]];
        }
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> arr = split(s, ' ');
        if(pattern.size() != arr.size()) return false;
        int n = arr.size();
        string str1 = helper1(pattern);
        string str2 = helper2(arr);
        return str1 == str2;
    }
};