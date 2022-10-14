class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0 , mod = 1e9 + 7;;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            ans = (ans + mp[nums[i] -rev(nums[i])]++)%mod;
            
                    // res = (res + m[n - rev(n)]++) % 1000000007;

        }
        return ans;
    }
    int reverseNumber(int n){
        int reverseNum = 0;
        while(n>0){
            int remainder = n % 10;
            reverseNum = reverseNum * 10 + remainder;
            n /= 10;
        }
        return reverseNum;
    }
    int rev(int a) {
        int b = 0;
        while (a > 0) {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
    
};