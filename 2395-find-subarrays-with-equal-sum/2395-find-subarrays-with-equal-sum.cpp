class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
            int n = nums.size();
            if(n==2) return false;
            unordered_map<int, int> hashmap;
            int i = 0, j = 1;
            while(j<n){
                    int sum = nums[i++] + nums[j++];
                    if(hashmap[sum]){
                            return true;
                    }
                    hashmap[sum]++;
            }
        return false;
    }
};