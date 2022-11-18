using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for(int i = 1; i<=n; i++){
            qu.push(i);
        }
        while(qu.size()!=1){
            int x = k;
            while(x>1){
                int r=qu.front();
                qu.pop();
                qu.push(r);
                x--;
            }
            qu.pop();
        }
        return qu.front();
    }
};