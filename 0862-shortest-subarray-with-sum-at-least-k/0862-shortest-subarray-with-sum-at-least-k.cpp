using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        deque<pair<int, long long>>dq;
        long long sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);
            // cout<<"Sum: "<<sum<<" ans: "<<ans<<endl;
            while(!dq.empty() && (sum - dq.front().second)>=k){
                // cout<<"ans under while1: "<<ans<<" "<<dq.front().second<<" i "<<i<<endl;
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
            while(!dq.empty() && sum<dq.back().second){
                dq.pop_back();
            }
            dq.push_back({i, sum});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};