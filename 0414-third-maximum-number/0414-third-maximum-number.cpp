using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
       map<int, int, greater<int> > mymap;
        for(auto n: nums){
            mymap[n]++;
        }
        int kthLargest = mymap.size()>=3 ? 3 : 1;
        int ans = 0;
        for(auto i :mymap){
            if(kthLargest == 0) break;
            ans = i.first;
            kthLargest--;
        }
        return ans;
    }
};