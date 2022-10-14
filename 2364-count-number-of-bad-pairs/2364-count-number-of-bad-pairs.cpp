using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> badMap;
        int n = nums.size();
        long long cnt = 0;
        for(int i = 0; i<n;i++){
            cnt += badMap[nums[i]-i]++;
        }
        return 1L*n*(n-1)/2 - cnt;
    }
    
};