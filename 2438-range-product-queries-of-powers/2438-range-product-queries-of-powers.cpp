class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int m = 1e9+7;
        vector<int> power;
        for(int i = 0; i<32; i++){
            if(n&1){
                power.push_back(1<<i);
            }
            n >>=1;
        }
        for(auto que:queries){
            int start = que[0];
            int end = que[1];
            long p = 1;
            while(start<=end){
                p = (p*power[start++])%m;
            }
            ans.push_back(p);
        }
        return ans;
        
    }
};