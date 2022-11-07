class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int start = 0, end = 0;
        int ans = 0;
        int max_count = 0;
        unordered_map<char, int> mp;
        for(; end<n; end++){
            mp[answerKey[end]]++;
            max_count = max(max_count, mp[answerKey[end]]);
            while(end - start + 1 - max_count > k){
                mp[answerKey[start++]]--;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};