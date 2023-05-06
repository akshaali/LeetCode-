using namespace std;
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // vector<pair<int, int>> waiting[128];
        unordered_map<char, vector<pair<int,int>>> waiting;
        
        
        
        int ans = 0;
        
        for (int i = 0; i < words.size(); i++){
             // waiting[words[i][0]].emplace_back(i, 1);
            char ch = words[i][0];
            waiting[ch].emplace_back(i,1);
        }  
        for (char c : s) {
            // auto advance = waiting[c];
            auto advance = waiting[c];
            waiting.erase(c);
            for (auto it : advance){
                // cout<<"it.first: "<<it.first<<" it.second: "<<it.second<<" "<<endl;
                if(it.second == words[it.first].size()) ans++;
                char ch = words[it.first][it.second];
                waiting[ch].emplace_back(it.first, ++it.second);
                
                
                
                // waiting[words[it.first][it.second++]].push_back(it);
            }
                
        }
        // return waiting[0].size();
        return ans;
    }
};