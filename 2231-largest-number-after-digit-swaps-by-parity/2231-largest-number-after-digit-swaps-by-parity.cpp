class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        string nums = to_string(num);
        for(auto n: nums){
            if((n - '0')&1) {
                odd.push(n - '0');
            }else{
                even.push(n - '0');
            }
        }
        int ans = 0;
        for(auto n: nums){
            ans *=10;
            if((n - '0')&1) {
                ans += odd.top();
                odd.pop();
            }else{
                ans += even.top();
                even.pop();
            }
        }
        return ans;
    }
};