class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int sum = 0;
        for(auto alt: gain){
            sum += alt;
            if(sum>ans) ans = sum;
        }
        return ans;
    }
};