class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //     //prefix sum
    //     int ans = 0, sum = 0;
    //     unordered_map<int, int> sumFreq;
    //     sumFreq[sum] = 0;
    //     for(auto n: nums){
    //         sum += n;
    //         int sumOccured = sum - k;
    //         if(sumFreq.count(sumOccured)){
    //             ans += sumFreq[sumOccured];
    //         }
    //         sumFreq[sum]++;
    //     }
    //     return ans;
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};