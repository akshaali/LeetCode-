using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> perm;
        int size = nums.size();
        vector<int>freq(size, 0);
        solve(nums, ans, perm, freq);
        return ans;
        
    }
    void solve(vector<int> nums, vector<vector<int>> & ans, vector<int> perm, vector<int>freq){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int j = 0; j<nums.size(); j++){
            if(!freq[j]){
                perm.push_back(nums[j]);
                freq[j] = 1;
                solve(nums, ans, perm, freq);
                freq[j] = 0;
                perm.pop_back();
            }
        }
    }
};