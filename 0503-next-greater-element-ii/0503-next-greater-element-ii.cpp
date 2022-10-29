using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 0; i<2*n-1; i++){
            int index = i%n;
            // cout<<i%n<<endl;
            while(!st.empty() && nums[st.top()]<nums[index]){
                // cout<<"st.top "<<st.top()<<" "<<nums[index]<<endl;
                ans[st.top()] = nums[index];
                st.pop();
            }
            st.push(index);
        }
        return ans;
        
    }
};