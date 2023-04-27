class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum3 = nums[i] + nums[left] + nums[right];
                if(sum3<0) left++;
                else if(sum3>0) right--;
                else{
                    vector<int>triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]);
                    ans.push_back(triplet);
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                    
                }
            }
        }
        
        return ans;   
    }
};