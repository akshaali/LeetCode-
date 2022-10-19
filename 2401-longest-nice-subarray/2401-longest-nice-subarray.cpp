using namespace std;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //sliding window
        int ans = 0;
        int checkMask = 0;
        int j = 0;
        for(int i =0; i<nums.size(); i++){
            // cout<<checkMask<<"  "<<ans<<endl;
            if((checkMask & nums[i]) == 0){
                ans = max(ans, i-j+1);
            }else{
                while((nums[i]&checkMask) && j<nums.size() && j<=i){
                    checkMask ^= nums[j];
                    j++;
                }
            }
            checkMask |= nums[i];
        }
        return ans;
    }
};