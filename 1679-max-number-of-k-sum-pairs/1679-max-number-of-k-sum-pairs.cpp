class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            int numSum = k - nums[i];
            if(mp[numSum]>0){
                mp[numSum]--;
                if( mp[nums[i]]>0){
                    mp[nums[i]]--;
                    count++;
                }else{
                    mp[numSum]++;
                }
                
            }
        }
        return count;
    }
};