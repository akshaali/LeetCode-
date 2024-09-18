class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(asteroids[i]);
            else{
                int val = asteroids[i];
                while(st.size() && st.top()*val<0){
                    int top = st.top();
                    if(top<0 && val>0) break;
                    if(abs(val)==abs(top)) val = 0;
                    else if(abs(val)<abs(top)) val = top;
                    st.pop();
                }
                if(val != 0) st.push(val);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};