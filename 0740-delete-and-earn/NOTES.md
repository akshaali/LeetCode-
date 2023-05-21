int deleteAndEarn(vector<int>& nums) {
unordered_map<int, int>mp;
for(auto n :nums) mp[n]++;
set<int> numSet(nums.begin(), nums.end());
vector<int> numset(numSet.begin(), numSet.end());
sort(numset.begin(), numset.end());
int n = numset.size();
return solve(n-1, numset, mp);
}
};
```
2. Recursive Memoization top-down dynamic programming approach
```
int solve(int index,vector<int> numSet, unordered_map<int, int>mp, vector<int> & dp){
if(index<0) return 0;
int num = numSet[index];
int freq = mp[num];
if(index == 0) return num*freq;
if(dp[index] != -1) return dp[index];
int notPick = INT_MIN;
int pick = INT_MIN;
if(numSet[index-1] == numSet[index]-1){
pick = freq*num + solve(index-2, numSet, mp, dp);
notPick = solve(index-1, numSet, mp, dp);
}else{
pick = freq*num + solve(index-1, numSet, mp, dp);
}
int ans = max(pick, notPick);
dp[index] = ans;
return ans;
}
int deleteAndEarn(vector<int>& nums) {
unordered_map<int, int>mp;
for(auto n :nums) mp[n]++;
set<int> numSet(nums.begin(), nums.end());
vector<int> numset(numSet.begin(), numSet.end());
sort(numset.begin(), numset.end());
int n = numset.size();
vector<int>dp(n+1, -1);
return solve(n-1, numset, mp, dp);
}
```
3. Bottom-up dynamic programming approach
```
​