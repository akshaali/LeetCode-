using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // long long ans = 0;
        // int n = costs.size();
        // priority_queue<int,vector<int>,greater<int>> pq_beg; 
        // priority_queue<int,vector<int>,greater<int>> pq_end;
        // int l=0,r=n-1;
        // while(k>0){
        //     while(pq_beg.size()<n && l<=r) pq_beg.push(costs[l++]);
        //     while(pq_beg.size()<n && r>=l) pq_beg.push(costs[r--]);
        //     int top_beg = pq_beg.size() ? pq_beg.top(): INT_MAX;
        //     int top_end = pq_end.size() ? pq_end.top() : INT_MAX;
        //     if(top_beg<top_end){
        //         ans += top_beg;
        //         pq_beg.pop();
        //         k--;
        //     }else{
        //         ans += top_end;
        //         pq_end.pop();
        //         k--;
        //     }
        // }
        // return ans;
        priority_queue<int,vector<int>,greater<int>> pq1; 
        priority_queue<int,vector<int>,greater<int>> pq2; 
        long long ans=0; // total cost
        int l=0,r=costs.size()-1; // left and right pointer of the window
        int cnt=0; // number of candidates in the current window
        while(cnt<k){ // add the first k candidates to the window
            while(pq1.size()<candidates && l<=r) // add the first candidates to the window
                pq1.push(costs[l++]); 
            while(pq2.size()<candidates && r>=l) // add the last candidates to the window
                pq2.push(costs[r--]);
            
            int top1 = pq1.size()>0?pq1.top():INT_MAX; // if the first window is full, then the top of the first window is the minimum cost of the first candidates
            int top2 = pq2.size()>0?pq2.top():INT_MAX; // if the last window is full, then the top of the last window is the minimum cost of the last candidates
            
            if(top1<=top2){ // if the first window is cheaper, then add the first candidate to the window
                ans+=top1;
                pq1.pop(); 
            }
            else{ // if the last window is cheaper, then add the last candidate to the window
                ans+=top2;
                pq2.pop();
            }
            cnt++; // increase the number of candidates in the window
        }
        return ans; // return the total cost
    }
};