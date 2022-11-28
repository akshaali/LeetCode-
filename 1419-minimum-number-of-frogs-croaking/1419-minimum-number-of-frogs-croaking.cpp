using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if(n %5 != 0 || croakOfFrogs[0] != 'c' || croakOfFrogs[n-1] != 'k') return -1;
        int ans = 0, activeFrog = 0;
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        for(auto ch : croakOfFrogs){
            // cout<<"ch: "<<ch<<endl;
            switch(ch){
                case 'c': {
                    activeFrog++;
                    c++;
                    ans = max(ans, activeFrog);
                    // cout<<"activeFrog"<<" "<<ans<<" "<<c<<endl;
                    break;
                }
                case 'r': {
                    r++;
                    break;
                }
                case 'o' :{
                    o++;
                    break;
                }
                case 'a': {
                    a++;
                    break;
                }
                case 'k': {
                    activeFrog--;
                    k++;
                    break;
                }
            }
            if(!isSequencial(c,r,o,a,k)) return -1;
        }
        if(c!=r || r!=o || o!=a || a!=k) return -1;
        return ans;
    }
    bool isSequencial(int c, int r, int o, int a, int k){
        // cout<<c<<" "<<r<<" "<<o<<" "<<a<<" "<<k<<endl;
        if(c>=r && r>=o && o>=a && a>=k) return true;
        return false;
    }
};