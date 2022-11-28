class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int n = fruits.size();
        int ans = 0;
        for(; right<n; right++){
            mp[fruits[right]]++;
            while(left<n && mp.size()>2){
                if(mp[fruits[left]] > 1){
                    mp[fruits[left]]--;
                }else{
                    mp.erase(fruits[left]);
                }
                left++;
            }
            if(mp.size() <= 2){
                ans = max(ans, right - left + 1);
                
            }
        }
        return ans;
    }
};