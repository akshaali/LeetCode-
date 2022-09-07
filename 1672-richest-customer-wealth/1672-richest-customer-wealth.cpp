class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = 0;
        for(auto i:accounts) 
            m=max(m,accumulate(i.begin(),i.end(),0));
        return m;
    }
};