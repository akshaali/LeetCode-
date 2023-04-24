class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26] = {0};
        for(int i = 0; i<s.length(); i++){
            arr[s[i]-97]++;
            if(arr[s[i]-97] == 2) return s[i];
        }
        return s[0];
    }
};