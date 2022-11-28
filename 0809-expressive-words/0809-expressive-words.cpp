class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(auto w: words) if(canBeMade(s, w)) ans++;
        return ans;
    }
    bool canBeMade(string target, string word){
        int n = target.size(), m = word.size(), j = 0;
        for(int i = 0; i<n; i++){
            if(j<m && target[i] == word[j]) j++;
            else if(i>1 && target[i-2] == target[i-1] && target[i-1] == target[i]);
            else if(i>0 && i<n-1 && target[i-1] == target[i] && target[i] == target[i+1]);
            else return false;
        }
        return j == m;
    }
};