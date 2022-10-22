using namespace std;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // long long sum = 0;
        // int curr = 1;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<nums.size() && k>0; i++){
        //     int take = max(0, min(nums[i] - curr, k));
        //     sum += (curr + take) * (curr + take - 1) / 2 - curr * (curr - 1) / 2;
        //     k -= take;
        //     curr = nums[i] + 1;
        //     // cout<<take<<" "<<k<<" "<<curr<<" "<<sum<<endl;
        // }
        // return sum;
        long long res = 0, cur = 1;
    nums.push_back(INT_MAX);
    sort(begin(nums), end(nums));
    for (int i = 0; k > 0 && i < nums.size(); ++i) {
        int take = max(0, min(k, nums[i] - (int)cur));
        res += (cur + take) * (cur + take - 1) / 2 - cur * (cur - 1) / 2;
        k -= take;
        cur = (long long)nums[i] + 1;
    }
    return res;
    }
    
};