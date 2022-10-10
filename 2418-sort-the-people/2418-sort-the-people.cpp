class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> heightName;
        vector<string> ans;
        for(int i = 0; i < heights.size(); i++){
            heightName[heights[i]] = names[i];
        }
	// for (auto i = heightName.end(); i
	// 	!= heightName.begin(); i--) {
	// 	ans.push_back(i->second);
	// }
        for(auto item: heightName){
            ans.push_back(item.second);
        }
        return ans;
    }
};