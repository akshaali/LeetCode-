using namespace std;
class Solution {
    bool checkMaps(unordered_map<char, int>shash, unordered_map<char, int>phash){
        for(auto ch: phash){
            if(shash[ch.first] != phash[ch.first]) return false;
        }
        return true;
    }
    void print(unordered_map<char, int>mp){
        for(auto ch: mp){
            cout<<ch.first << ": "<<ch.second<<"  ";
        }
        cout<<endl;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>shash;
        unordered_map<char, int>phash;
        vector<int> ans;
        int lenS = s.size();
        int lenP = p.size();
        int left = 0, right = 0;
        while(right<lenP){
            shash[s[right]]++;
            phash[p[right]]++;
            right++;
        }
        // print(shash);
        // print(phash);
        while(right<lenS){
           if(checkMaps(shash, phash)){
               ans.push_back(left);
           }
            // print(shash);
            // print(phash);
            // cout<<"right: "<<right<<" left: "<<left<<endl;
            shash[s[right]]++;
            shash[s[left]]--;
            left++;
            right++;
        }
        //  print(shash);
        // print(phash);
        // cout<<"right: "<<right<<" left: "<<left<<endl;
        if(checkMaps(shash, phash)){
               ans.push_back(left);
         }
        return ans;
    }
};