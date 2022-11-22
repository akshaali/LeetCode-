class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.size();
        for(int i = 0; i<n; i++){
            if(isVowel(word[i])){
                 ans += (long)(i+1)*(long)(n-i);
            }
        }
        return ans;
    }
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
};