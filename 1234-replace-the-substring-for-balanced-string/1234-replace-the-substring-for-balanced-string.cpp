using namespace std;
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }
        int target = n/4;
        int ans = n;
        int start =0, end = 0;
        for(; end<n; end++){
            mp[s[end]]--;
            if(isBalanced(mp, target)){
                ans = min(ans, end - start + 1);
                while(start<=end){
                    mp[s[start]]++;
                    start++;
                    if(isBalanced(mp, target)) ans = min(ans, end - start +1);
                    else break;
                }
            }
        }
        
        return ans;
    }
    bool isBalanced(unordered_map<char, int> mp, int target){
        for(auto item: mp){
            if(item.second>target) return false;
        }
        return true;
    }
};