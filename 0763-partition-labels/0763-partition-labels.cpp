using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        for(auto i : mp){
            cout<<i.first<<"  "<<i.second<<endl;
        }
        vector<int> ans;
        for(int i = 0; i <s.size(); i++){
            int maxRange = mp[s[i]];
            int j = i;
            while(j<maxRange){
                maxRange = max(mp[s[j]],maxRange);
                j++;
            }
           cout<<"j & i values "<<j<<" "<<i<<endl;
           ans.push_back(j-i+1);
           i = j;
        }
        return ans;
    }
};