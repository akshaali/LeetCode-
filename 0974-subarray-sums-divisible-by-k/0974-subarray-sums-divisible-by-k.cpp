class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>freqRemainder(k);
        //to capture the first occurance of subarray whose sum's divisible by k
        freqRemainder[0] = 1;
        int sum = 0, ans = 0;
        for(auto n: nums){
            sum += n;
            int remainder = (sum%k + k)%k;
            ans +=freqRemainder[remainder]++;   
        }
        return ans;
    }
};