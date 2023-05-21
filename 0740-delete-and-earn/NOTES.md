int n = numset.size();
vector<int>dp(n+1, -1);
return solve(n-1, numset, mp, dp);
}
```
3. Bottom-up dynamic programming approach
```
int deleteAndEarn(vector<int>& nums) {
unordered_map<int, int>mp;
for(auto n :nums) mp[n]++;
set<int> numSet(nums.begin(), nums.end());
vector<int> numset(numSet.begin(), numSet.end());
sort(numset.begin(), numset.end());
int n = numset.size();
vector<int>dp(n+1, -1);
dp[0] = 0;
dp[1] = numset[0]*mp[numset[0]];
for(int i = 2; i<=n; i++){
int num = numset[i-1];
int freq = mp[num];
int notPick = INT_MIN;
int pick = INT_MIN;
if(numset[i-2] == numset[i-1]-1){
pick = freq*num + dp[i-2];
notPick = dp[i-1];
}else{
pick = freq*num + dp[i-1];
}
dp[i] = max(notPick, pick);
}
return dp[n];
}
```
4. Bottom-up space optimized dynamic programming approach
```
​