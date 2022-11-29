using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left;
        vector<int> right;
        for(int i = 0; i<n; i++) left.push_back(i+1);
        for(int i = 0; i<n; i++) right.push_back(n-i);
        //  for(int i = 0; i<n; i++){
        //     cout<<"left[i]:1 "<<left[i]<<" right[i]:1 "<<right[i]<<endl;
        // }
        stack<int> nextLess;
        stack<int> prevLess;
        
        for(int i = 0; i<arr.size(); i++){
            while(!nextLess.empty() && arr[nextLess.top()]>arr[i]){
                // cout<<i<<" here we are "<<nextLess.top()<<endl;
                right[nextLess.top()] = i-nextLess.top();
                nextLess.pop();
            }
            nextLess.push(i);
            while(!prevLess.empty() && arr[prevLess.top()]>=arr[n-i-1]){
                left[prevLess.top()] = prevLess.top()-(n-i-1);
                prevLess.pop();
            }
            prevLess.push(n-i-1);
        }
        for(int i = 0; i<n; i++){
            // cout<<"left[i]: "<<left[i]<<" right[i]: "<<right[i]<<endl;
            ans = (ans + (long)arr[i]*(long)left[i]*(long)right[i])%mod;
        }
        return ans;
    }
};