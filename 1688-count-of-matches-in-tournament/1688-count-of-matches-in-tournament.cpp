using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {
        int match=0;
        while(n>1){
            cout<<(n&1)<<endl;
            match += n/2;
            n = (n+1)/2;
        }
        return match;
    }
};