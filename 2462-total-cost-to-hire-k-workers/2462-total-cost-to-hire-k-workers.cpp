using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> pq_beg; 
        priority_queue<int,vector<int>,greater<int>> pq_end;
        int l=0,r=n-1;
        int cnt = 0;
        while(cnt<k){
            while(pq_beg.size()<candidates && l<=r) pq_beg.push(costs[l++]);
            while(pq_end.size()<candidates && r>=l) pq_end.push(costs[r--]);
            int top_beg = pq_beg.size()>0 ? pq_beg.top(): INT_MAX;
            int top_end = pq_end.size()>0 ? pq_end.top() : INT_MAX;
            if(top_beg<=top_end){
                ans += top_beg;
                pq_beg.pop();
            }else{
                ans += top_end;
                pq_end.pop();
            }
             cnt++;
        }
        return ans;
        
    }
};




