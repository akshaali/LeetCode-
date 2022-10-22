class Solution {
public:
    int minFlips(string target) {
        int ans = 0, curr = 0;
        for(auto bit: target){
            if((bit - '0') != curr){
                ans++;
                curr = bit - '0';
            }
        }
        return ans;
    }
};