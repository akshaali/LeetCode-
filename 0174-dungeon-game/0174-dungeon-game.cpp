using namespace std;
class Solution {
public:
        void print(vector<int> arr){
                cout<<"[";
                for(auto a: arr){
                        cout<<a<<", ";
                }
                cout<<"]"<<endl;
        }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int>prev(n, 0);
        for(int i = m-1; i>=0; i--){
                vector<int>curr(n,0);
                for(int j = n-1; j>=0; j--){
                        if(i == m-1 && j == n-1){
                               curr[j] =  (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
                                continue;
                        }
                        int up = 1e9;
                        int left = 1e9;
                        if(i<m-1){
                                 up = prev[j] - dungeon[i][j];
                        }
                        if(j<n-1){
                                // cout<<"here "<<j<<" i: "<<i<<endl;
                                left = curr[j+1] -  dungeon[i][j];
                                // cout<<left<<endl;
                        }
                        // cout<<"left:   "<<left<<endl;
                        int minHealthRequired =  min(up , left);
                        // cout<<j<<" "<<up<<" "<<left<<" "<<minHealthRequired<<endl;
                        curr[j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;
                }
                // print(curr);
                prev = curr;
        }
        return prev[0];
    }
};