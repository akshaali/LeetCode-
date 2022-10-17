class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // extra space 
        // vector<int> ans(pref.size()) ;
        // ans[0] = pref[0];
        // for(int i = 1; i<pref.size(); i++){
        //     ans[i] = (pref[i]^pref[i-1]);
        // }
        // return ans;
        //in-place
        for(int i = pref.size()-1; i>0; i--){
            pref[i] ^=pref[i-1];
        }
        return pref;
    }
};