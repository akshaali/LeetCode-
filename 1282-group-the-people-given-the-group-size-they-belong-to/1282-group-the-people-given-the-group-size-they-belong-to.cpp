class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> obj;
        vector<vector<int>> out;
        for (int i=0; i<groupSizes.size(); i++) {
            int key = groupSizes[i];
            if (obj.count(key) > 0) { // check existing groups to fill
                obj[key].push_back(i);
            } else { // create a new group
                obj[key] = vector<int>{i};
            }
            if (obj[key].size() == key) { // group is full
                out.push_back(obj[key]);
                obj.erase(key);
            }
        }
        return out;
    }
};