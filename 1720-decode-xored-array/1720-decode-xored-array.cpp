class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for(auto i: encoded){
            res.push_back(i^res.back());
        }
        return res;
        
    }
};