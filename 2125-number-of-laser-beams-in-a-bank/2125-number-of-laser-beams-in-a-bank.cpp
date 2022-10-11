using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0;
        int ans;
        for(auto &i:bank){
            curr = count(i.begin(), i.end(), '1');
            cout<<curr<<" "<<prev<<endl;
            if(curr){
                ans += (prev*curr);
                cout<<ans<<endl;
                prev = curr;
            }
        }
        return ans;
    }
};