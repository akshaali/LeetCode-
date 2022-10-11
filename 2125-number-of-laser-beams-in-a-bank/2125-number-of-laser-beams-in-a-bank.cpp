class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0;
        int ans = 0;
        for(auto &i:bank){
            curr = count(i.begin(), i.end(), '1');
            if(curr){
                ans += (prev*curr);
                prev = curr;
            }
        }
        return ans;
    }
};