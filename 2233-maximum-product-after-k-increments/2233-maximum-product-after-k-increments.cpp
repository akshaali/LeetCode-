using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        // max heap - priority que
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n: nums) pq.push(n);
        long long ans = 1, mod = 1e9+7;
        while(k>0){
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest+1);
            k--;
        }
        while (!pq.empty()) {
            ans = ((ans % mod) * (pq.top() % mod)) % mod;
            pq.pop();
        }
        return (int)ans;
        
    }
};