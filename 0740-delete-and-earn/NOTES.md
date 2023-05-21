}
```
int deleteAndEarn(vector<int>& nums) {
unordered_map<int, int>mp;
for(auto n :nums) mp[n]++;
set<int> numSet(nums.begin(), nums.end());
vector<int> numset(numSet.begin(), numSet.end());
sort(numset.begin(), numset.end());
int n = numset.size();
vector<int>dp(n+1, -1);
int earn1 = 0;
int earn2 = numset[0]*mp[numset[0]];
for(int i = 2; i<=n; i++){
int num = numset[i-1];
int freq = mp[num];
int notPick = INT_MIN;
int pick = INT_MIN;
if(numset[i-2] == numset[i-1]-1){
pick = freq*num + earn1;
notPick = earn2;
}else{
pick = freq*num + earn2;
}
int curr = max(notPick, pick);
earn1 = earn2;
earn2 = curr;
}
return earn2;
}
```
​