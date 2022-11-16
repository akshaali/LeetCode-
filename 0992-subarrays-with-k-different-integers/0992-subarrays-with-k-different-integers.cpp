using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKDistinctSubarray(nums, k) - atmostKDistinctSubarray(nums, k-1);
    }
    
    int atmostKDistinctSubarray(vector<int> nums, int k){
        int pt1 = 0, pt2 = 0, n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(; pt2<n; pt2++){
             mp[nums[pt2]]++;
            while(pt1<n && mp.size()>k){
                if(mp[nums[pt1]]>1){
                    mp[nums[pt1]]--;
                }else{
                    mp.erase(nums[pt1]);
                }
                pt1++;
            }
            ans += (pt2-pt1+1);
        }
        return ans;
    }
};