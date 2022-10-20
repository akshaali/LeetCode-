using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int pt1 = 0, pt2=0;
        vector<int> inter{{intervals[0]}};
        int maxi = inter[1];
        for(int i = 1; i<intervals.size(); i++){
            // cout<<i<<" maxi values: "<<maxi<<" inter 0th & 1th: "<<inter[0]<<" "<<inter[1]<<endl;
            if(intervals[i][0]<=maxi){
                maxi = max(maxi, intervals[i][1]);
            }else{
                inter[1] = maxi;
                ans.push_back(inter);
                inter = intervals[i];
                maxi = inter[1];
            }
        }
         // cout<<" Enddd maxi values: "<<maxi<<" inter 0th & 1th: "<<inter[0]<<" "<<inter[1]<<endl;
        // vector<int> overlapped{{intervals[pt1][0], maxi}};
        inter[1] = maxi;
        ans.push_back(inter);
        return ans;
    }
};