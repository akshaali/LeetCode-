class Solution {
     bool isSubsequence(string s, string t) {
        int tSize = t.size(), sSize = s.size();
        int i = 0, j = 0;
        while(i<tSize && j<sSize){
            if(s[j] == t[i]){
                j++;
            }
            i++;
        }
        return j == sSize;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // int ans = 0;
        // for(int i = 0; i<words.size(); i++){
        //     if(isSubsequence(words[i], s)) ans++;
        // }
        // return ans;
        int count = 0;
        //we will be form map to count occurences of particular word to avoid re calculation and this will reduce time
        unordered_map<string,int> mp;
        for(int i= 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto x : mp){
            string str = x.first;
            int n = str.size();
            int i = 0, j = 0;
            while(i < n && j < s.size()){
                if(str[i] == s[j]){
                    i++;
                }
                j++;
            }
            if(i == n){
                count += x.second;  //if we reach the length of string str then this word in our string s. so we increase our count by the number of times it occurred in words instead of incrementing by 1
            }
        }
        
        return count++;
    }
};