class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>hash(n,0);
        int maxi = 1;
        int lastIndex = 0;
        for(int index = 0; index<n; index++){
            hash[index] = index;
            for(int prevIndex = 0; prevIndex<index; prevIndex++){
                if(nums[index]%nums[prevIndex] == 0 && dp[index]<1+dp[prevIndex]){
                    dp[index] = 1 + dp[prevIndex];
                    hash[index] = prevIndex;
                    
                }
            }
            if(dp[index]>maxi){
                maxi = dp[index];
                lastIndex = index;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(nums.begin(), nums.end());
        return ans;
    }
};