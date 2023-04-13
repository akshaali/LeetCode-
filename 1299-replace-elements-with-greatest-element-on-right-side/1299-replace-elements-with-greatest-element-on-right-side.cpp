class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            ans[i] = st.top();
            if(arr[i]>st.top()){
                st.push(arr[i]);
            }
        }
        return ans;
    }
};