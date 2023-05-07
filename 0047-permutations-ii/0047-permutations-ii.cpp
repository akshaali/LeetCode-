using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        int size = nums.size();
        vector<int>freq(size, 0);
        sort(nums.begin(), nums.end());
        solve(nums, ans, perm, freq);
        return ans;
        
    }
    void solve(vector<int> nums, vector<vector<int>> & ans, vector<int> perm, vector<int>freq){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int j = 0; j<nums.size(); j++){
            if(freq[j]) continue;
            if(j>0 && nums[j-1] == nums[j] && !freq[j-1]) continue;
                freq[j] = 1;
                perm.push_back(nums[j]);
                solve(nums, ans, perm, freq);
                freq[j] = 0;
                perm.pop_back();
        }
    }
};