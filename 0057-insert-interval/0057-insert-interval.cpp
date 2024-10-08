class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        int i = 0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int mini = newInterval[0];
        int maxi = newInterval[1];
        while(i<n && intervals[i][0]<=maxi){
            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
            i++;
        }
        ans.push_back(vector<int>{mini, maxi});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};