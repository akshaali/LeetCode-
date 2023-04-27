class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j<n; j++){
                if(j>i+1 && nums[j-1] == nums[j]) continue;
                int left = j+1;
                int right = n-1;
                while(left<right){
                     long long int  first2 = nums[i] + nums[j];
                     long long int  last2 = nums[left] + nums[right];
                    if(first2<(target-last2)) left++;
                    else if(first2>(target-last2)) right--;
                    else{
                        vector<int>quadruplets;
                        quadruplets.push_back(nums[i]);
                        quadruplets.push_back(nums[j]);
                        quadruplets.push_back(nums[left]);
                        quadruplets.push_back(nums[right]);
                        ans.push_back(quadruplets);
                        left++;
                        while(left<right && nums[left] == nums[left-1]) left++;
                    }
                }
            }
        }
        
        return ans; 
        
    }
};