class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; //word pointer
        int m = 0, n = 0; // char pointer
        int size1 = word1.size() , size2 = word2.size();
        while(i<size1 && j<size2){
            if(word1[i][m++] != word2[j][n++]){
                return false;
            }
            if(m>=word1[i].size()){
                i++;
                m = 0;
            }
             if(n>=word2[j].size()){
                j++;
                n = 0;
            }
        }
        return i == size1 && j == size2;
    }
};