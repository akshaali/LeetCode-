using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<float,vector<vector<int>>>mp;
        vector<vector<int>> ans;
        for(int i = 0; i<points.size(); i++){
            float dist = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            mp[dist].push_back(points[i]);
        }
        for(auto ele: mp){
           if(ans.size()<k){
               for(int i = 0; i<ele.second.size() && ans.size()<k; i++){
                   ans.push_back(ele.second[i]);
               }
           }else return ans;
        }
        return ans;
    }
};