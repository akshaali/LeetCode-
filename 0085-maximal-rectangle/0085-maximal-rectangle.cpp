class Solution {
public:
    vector<int> nextSmallerElement(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = prevSmallerElement(heights);
        int ans = INT_MIN;
        for(int i = 0; i<heights.size(); i++){
            int area = (nse[i]-pse[i]-1)*heights[i];
            ans = max(area, ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<vector<int>>hist(rows, vector<int>(cols));
        for(int i = 0; i<cols; i++){
            hist[0][i] = matrix[0][i] == '0' ? 0 : 1;
        }
        for(int i = 1; i<rows; i++){
            for(int j = 0; j<cols; j++){
                hist[i][j] = matrix[i][j] == '0' ? 0 : hist[i-1][j] + 1;
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i<rows; i++){
            int area = largestRectangleArea(hist[i]);
            ans = max(area, ans);
        }
        return ans;
    }
};