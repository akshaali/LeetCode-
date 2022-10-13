class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
//         unordered_map<int, vector<int>> m;
//         for (int i = 0;  i < nums.size(); ++i)
//             m[nums[i]].push_back(i);
//         for(auto &(n, ids): m){
//             for(int i = 0; i< ids.size(); i++){
//                 for(int j = i+1; j<ids.size(); j++){
                    
//                 }
//             }
//         }
        for(int i = 0; i< nums.size(); i++){
                for(int j = i+1; j<nums.size(); j++){
                    if(nums[i] == nums[j]){
                        ans +=( (i*j)%k ==0 );
                    }
                }
            }
        return ans;
        
        
        
        
    }
};