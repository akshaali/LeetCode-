class Solution 
{
public:
    int dp[8000][71];
    int n,m;
    int find(vector<vector<int>>&mat,int r,int sum,int &target)
    {
        if(r>=m)
        {
            return abs(sum-target);
        }
        if(dp[sum][r]!=-1) return dp[sum][r];

        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,find(mat,r+1,sum+mat[r][i],target));
            if(ans==0)
            {
                break;
            }
        }
        dp[sum][r]=ans;
        return ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        memset(dp,-1,sizeof(dp));
        m=mat.size();
        n=mat[0].size();
        return find(mat,0,0,target);
    }
};