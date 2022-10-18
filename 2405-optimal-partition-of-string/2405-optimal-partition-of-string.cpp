using namespace std;
class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_map<int,int> mp;
        mp[s[0]]++;
       for(int i = 1; i<s.size(); i++){
           if(mp[s[i]]){
               // cout<<"heyyyyyy"<<endl;
               ans++;
               mp.clear();
           }
           mp[s[i]]++;
       }
        ans = mp.size()? ans+1 :ans;
        return ans;
    }
};