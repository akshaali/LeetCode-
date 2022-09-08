class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(auto word: sentences){
            int spaceCount = count(word.begin(), word.end(), ' ') +1;
            maxi = max(maxi, spaceCount );
        }
        return maxi;
        
        
    }
};