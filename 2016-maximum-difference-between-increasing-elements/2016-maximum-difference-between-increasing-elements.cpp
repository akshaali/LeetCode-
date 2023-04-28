using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int pt1 =0, pt2 = 1;
        int n = nums.size();
        while(pt1<pt2 && pt2<n){
            // cout<<pt1<<" "<<pt2<<" "<<maxDiff<<endl;
            if(nums[pt2]<nums[pt1]){
                pt1 = pt2;
            }
            maxDiff = max(maxDiff, nums[pt2]-nums[pt1]);
            pt2++;
        }
        return maxDiff ? maxDiff : -1;
    }
};