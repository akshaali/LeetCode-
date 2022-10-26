using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, n = cardPoints.size();
        for(int i = 1; i<n; i++){
            cardPoints[i] += cardPoints[i-1];
        }
        if(k == n) return cardPoints[n-1];
        // for(auto pt : cardPoints) cout<<"cardPoints "<<pt<<endl;
        int windowTotal = cardPoints[n-k-1];
        ans = max(cardPoints[n-1]-windowTotal, ans);
        // cout<<"window Total "<<windowTotal<<" ans "<<ans<<endl;
        for(int i = 1; i<=k; i++){
            windowTotal = cardPoints[n-k-1+i] - cardPoints[i-1];;
            ans = max(ans, cardPoints[n-1]-windowTotal);
            // cout<<"window Total= "<<windowTotal<<" ans= "<<ans<<" i "<<i<<endl;
        }
        return ans;
        
    }
};