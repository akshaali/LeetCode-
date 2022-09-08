class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        unordered_map<int, int> count;
        for(auto i:stones){
            count[i]++;
        }
        for(auto i:jewels){
            res += count[i];
        }
        return res;
        
    }
};