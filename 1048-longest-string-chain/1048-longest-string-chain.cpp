class Solution {
public:
    bool check(string &s1, string &s2){
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 != n2+1) return false;
        int pt1 = 0, pt2 = 0;
        while(pt1<n1){
            if(pt2<n2 && s1[pt1] == s2[pt2]){
                pt1++;
                pt2++;
            }else{
                pt1++;
            }
        }
        if(pt1 == n1 && pt2 == n2) return true;
        return false;
    }
   static bool compare(string &s1,string &s2)
    {
    return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        vector<int>dp(n, 1);
        int maxi = 1;
        for(int index = 0; index<n; index++){
            for(int prevIndex = 0; prevIndex<index; prevIndex++){
                if(check(words[index], words[prevIndex])){
                    dp[index] = max(dp[index], 1+dp[prevIndex]);
                }
            }
            maxi = max(maxi, dp[index]);
        }
        return maxi;
        
    }
};