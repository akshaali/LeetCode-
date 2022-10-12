class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        int pair = 0;
        for(auto i:s){
            if(i == '|'){
                if(pair>0){
                    pair--;
                }else{
                    pair++;
                }
            }else if(pair == 0 && i == '*'){
                ans++;
            }
        }
        return ans;
    }
};