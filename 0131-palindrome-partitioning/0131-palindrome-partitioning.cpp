using namespace std;
class Solution {
public:
    void print(vector<string> path){
        for(auto s : path){
            cout<<s<<" ";
        }
        cout<<endl;
    }
     void solve(int index, int n, vector<string> path, vector<vector<string>> &ans, string s){
        if(index == n){
            ans.push_back(path);
            return;
        }
        for(int i = index; i<n; i++){
            // cout<<"i: "<<i<<endl;
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                // print(path);
                solve(i+1, n, path, ans, s);
                path.pop_back();
            }
        }
        
    };
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    };
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        solve(0, n, path, ans, s);
        return ans;
    }
};