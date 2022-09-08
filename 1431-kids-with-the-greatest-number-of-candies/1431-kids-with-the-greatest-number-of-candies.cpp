class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandle = -1;
        vector<bool> res;
        for(auto i: candies){
            if(i>maxCandle){
                maxCandle = i;
            }
        }
        for(auto i: candies){
            if(i + extraCandies >= maxCandle){
                res.push_back(true);
            }else {
                res.push_back(false);
            }
        }
        return res;
        
    }
};