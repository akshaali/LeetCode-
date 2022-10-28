class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for(auto ch: s){
            int num = ch-'0';
            if(num/10 == 0){
                if(num>first){
                    second = first;
                    first = num;
                }else if(num>second && num<first) second = num;
            }
        }
        return second;
    }
};