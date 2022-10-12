using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start || goal){
            cout<<start<<" "<<goal<<" "<<(start^goal)<<endl;
            if((start^goal)&1){
                ans++;
            }
            start >>=1;
            goal >>=1;
        }
        return ans;
    }
};