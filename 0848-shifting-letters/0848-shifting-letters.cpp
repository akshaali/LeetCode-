using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int  m = 0;
        for(int i = shifts.size() - 1; i>=0; i--){
            m += (shifts[i] % 26);
            int x = ( m + (s[i] - 'a') ) % 26;
            s[i] = x + 'a';
            // cout<<m<<" "<<i<<endl;
        }
        return s;
    }
};