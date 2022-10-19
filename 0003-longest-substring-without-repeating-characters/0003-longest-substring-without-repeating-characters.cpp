class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pointer1 = 0;
        int pointer2 = 0;
        int longest = 0;
        unordered_map<char, int> mp;
        while(pointer2<s.size()){
            if(!mp[s[pointer2]]){
                mp[s[pointer2]]++;
                int size = mp.size();
                longest = max(size, longest);
                pointer2++;
            }else{
                mp.erase(s[pointer1]);
                pointer1++;
            }
        }
        return longest;
        
    }
};