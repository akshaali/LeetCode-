class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> freq;
        long long res = 0;
        for(auto rec: rectangles){
            res += freq[{rec[0]/__gcd(rec[0], rec[1]), rec[1]/__gcd(rec[0], rec[1])}]++;
        }
        return res;
    }
};