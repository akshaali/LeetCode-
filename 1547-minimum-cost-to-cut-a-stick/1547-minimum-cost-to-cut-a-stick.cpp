using namespace std;
class Solution {
public:
    int solve(int low, int high,vector<int>& cuts,vector<vector<int>>& dp){
        if(low > high) return 0;
        if(dp[low][high] != -1) return dp[low][high];
        int ans = INT_MAX;
        for(int k = low; k<=high; k++){
            int cost = cuts[high+1]-cuts[low-1] + solve(low, k-1,cuts,dp) + solve(k+1, high,cuts,dp);
            ans = min(ans, cost);
        }
        dp[low][high] = ans;
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for(int low = m-2; low>=1; low--){
            for(int high = 1; high <=m-2; high++){
                if(low > high) continue;
                int ans = INT_MAX;
                for(int k = low; k<=high; k++){
                    int cost = cuts[high+1]-cuts[low-1] + dp[low][k-1] + dp[k+1][high];
                    ans = min(ans, cost);
                }
                dp[low][high] = ans;
            }
        }
        
        return dp[1][m-2];
    }
};