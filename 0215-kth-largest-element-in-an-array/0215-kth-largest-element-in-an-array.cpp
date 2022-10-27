class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ans = INT_MIN;
        for(auto n: nums){
            pq.push(n);
        }
        while(!pq.empty() && k>0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};