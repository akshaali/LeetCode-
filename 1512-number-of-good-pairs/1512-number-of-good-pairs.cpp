using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> count;
        for (auto a: nums) {
            cout<<"resssss :  "<<res<<"  " <<count[a]<<endl;
            res += count[a]++;
            cout<<"resssss22222222==== :  "<<res<<"  " <<count[a]<<endl;
        }
        for(auto i: count){
            cout<<i.first<<" "<<i.second<<endl;
        }
        return res;
        
    }
};