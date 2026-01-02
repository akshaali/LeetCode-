class Solution {
public:
    bool static comparator(vector<int> i1, vector<int> i2) {
        if (i1[1] < i2[1]) return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        int ans = 1;
        int limit = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>=limit){
                limit = intervals[i][1];
                ans++;
            }
        }
        return n-ans;                       
    }
};