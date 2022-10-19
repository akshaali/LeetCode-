using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() == 0) return "";
        unordered_map<char, int> countT;
        unordered_map<char, int> window;
        for(auto ch:t) countT[ch]++;
        int have = 0, need = countT.size();
        pair<int, int> res;
        int j = 0;
        int len = INT_MAX;
        for(int i = 0; i <s.size(); i++){
            window[s[i]]++;
            if(countT[s[i]] && (window[s[i]] == countT[s[i]])){
                have++;
            }
            // cout<<j<<"  "<<i<<" "<<have<<" "<<need<<endl;
            while(have == need){
                if((i-j+1)<len){
                    res = {j,i};
                    len = i-j+1;
                }
                window[s[j]]--;
                if(countT[s[j]] && (window[s[j]] < countT[s[j]])){
                    have--;
                }
                j++;
            }
        }
        // cout<<res.first<<"  "<<res.second;
        if(len == INT_MAX) return "";
        else return s.substr(res.first,res.second-res.first+1);
        
    }
};