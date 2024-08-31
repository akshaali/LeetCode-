class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            vector<int>cnt(26, 0);
            int maxF = INT_MIN;
            for(int j = i; j<n; j++){
                int minF = INT_MAX;
                int indx = s[j] - 'a';
                maxF = max(maxF, ++cnt[indx]);
                // if(minF>=cnt[indx]-1){
                    // minF = cnt[indx];
                    for(int k = 0; k<26; k++){
                        minF = min(minF, cnt[k] == 0 ? INT_MAX : cnt[k]);
                    }
                // }
                // cout<<"string is: "<<s.substr(i, j-i+1)<<" maxF: "<<maxF<<" minF: "<<minF<<endl;
                ans += (maxF - minF);
            }
        }
        return ans;
    }
};