class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelCount = INT_MIN;
        int back = 0, front = 0;
        int currVowelCount = 0;
        while(front<s.size()){
            if(checkVowel(s[front])) currVowelCount++;
            if(front - back +1 == k){
                vowelCount = max(vowelCount, currVowelCount);
                if(checkVowel(s[back])) currVowelCount--;
                back++;
            }
            front++;
        }
        
        return vowelCount;
    }
    bool checkVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
};