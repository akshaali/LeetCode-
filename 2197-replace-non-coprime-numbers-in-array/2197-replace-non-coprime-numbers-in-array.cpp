using namespace std;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // stack<int> st;
        // for(auto n: nums){
        //     if(st.empty() || gcd(st.top(), n) == 1) st.push(n);
        //     else if(gcd(st.top(), n) > 1) {
        //         int top = st.top();
        //         st.pop();
        //         st.push(lcm(top, n));
        //     }
        //      cout<<st.top()<<" "<<n<<endl;;
        // }
        // int n = st.size(), i = 0;
        // vector<int> ans(n);
        // while(!st.empty()){
        //     ans[n-i-1] = st.top();
        //     st.pop();
        //     i++;
        // }
        // return ans;
        vector<int> res;
        for (int a: nums) {   
            while (true) {   
                int x = gcd(res.empty() ? 1 : res.back(), a);
                if (x == 1) break; // co-prime
                a *= res.back() / x;
                res.pop_back();
            }
            res.push_back(a);
        }
        return res;
    }
    int lcm(int a, int b){
        return (a/gcd(a,b)) * b;
    }
    int gcd(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;
        if(a>b) return gcd(a%b, b);
        return gcd(a, b%a);
    }
};
