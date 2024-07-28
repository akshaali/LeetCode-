class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        int max_freq = 0;
        vector<int>hash(26,0);
        while(right<n){
            hash[s[right] - 'A']++;
            max_freq = max(max_freq, hash[s[right] - 'A']);
            while((right - left + 1) - max_freq > k){
                hash[s[left]-'A']--;
                left++;
            }
            max_len = max(max_len, right-left+1);
            right++;
        }
        return max_len;
    }
};