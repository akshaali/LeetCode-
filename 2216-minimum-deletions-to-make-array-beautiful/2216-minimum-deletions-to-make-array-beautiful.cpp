class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for(auto n: nums){
            if(!st.empty() && st.top() == n && st.size()%2){
                ans++;
                // st.pop();
            }else{
             st.push(n);   
            }
        }
        return st.size()%2 ? ans+1 : ans;
    }
};