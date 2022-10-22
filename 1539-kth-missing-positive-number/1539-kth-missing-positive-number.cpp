using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        long long curr = 1;
        int ans = 0;
        nums.push_back(INT_MAX);
        for(int i = 0; i<nums.size() && k>0; i++){
            int gap = max(0, min(k, nums[i] - (int)curr));
            k -= gap;
            ans = (int)curr + gap - 1;
            curr = (long long)nums[i] + 1;
            // cout<<gap<<" "<<k<<" "<<curr<<" "<<ans<<endl;
        }
        return ans;
    }
};