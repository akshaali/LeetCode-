using namespace std;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = 0, curr = 1;;
        nums.push_back(INT_MAX);
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size() && k>0; i++){
            int take = max(0, min(nums[i] - (int)curr, k));
            sum += (curr + take) * (curr + take - 1) / 2 - curr * (curr - 1) / 2;
            k -= take;
            curr = (long long)nums[i] + 1;
            // cout<<take<<" "<<k<<" "<<curr<<" "<<sum<<endl;
        }
        return sum;
    }
    
};