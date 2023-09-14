using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int node = 2; node<=n; node++){
            int comb = 0;
            for(int root = 1; root<=node; root++){
                int left = root-1;
                int right = node-root;
                comb += dp[left]*dp[right];
            }
            dp[node] = comb;
        }
        return dp[n];
    }
};