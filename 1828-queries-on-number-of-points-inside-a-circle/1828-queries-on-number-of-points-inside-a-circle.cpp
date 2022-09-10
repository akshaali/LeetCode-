class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto q: queries){
            int count= 0, radius = q[2]*q[2];
            for(auto pt: points){
                count += (q[0]-pt[0])*(q[0]-pt[0]) +  (q[1]-pt[1])* (q[1]-pt[1]) <= radius;
            }
            res.push_back(count);
        }
        return res;
        
    }
};