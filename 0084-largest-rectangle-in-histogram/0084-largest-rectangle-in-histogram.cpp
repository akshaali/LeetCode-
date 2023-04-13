using namespace std;
class Solution {
private: 
    vector<int> nextSmaller(vector<int> arr, int n){
        stack<int> st;
        st.push(n);
        vector<int> ans(n, n);
        for(int i = 0; i<n; i++){
            while(st.top() != n && arr[st.top()]>arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    };
    vector<int> prevSmaller(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--){
            while(st.top() != -1 && arr[st.top()]>arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmaller(heights, n);
        
        vector<int> prev(n);
        prev = prevSmaller(heights,n);
        
        int area = INT_MIN;
        for(int i = 0; i<n; i++){
            // cout<<next[i]<<" "<<heights[i]<<endl;
            int newArea = heights[i] * (next[i]-prev[i]-1);
            area = max(area, newArea);
        }
        
        return area;
        
    }
};