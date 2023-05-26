using namespace std;
class Solution {
public:
        void print(vector<int> arr){
                cout<<"[ ";
                for(auto a: arr){
                        cout<<a<<", ";
                }
                cout<<"]"<<endl;
        }
        int minimum(vector<int> arr){
                int mini = INT_MAX;
                for(auto a: arr){
                        mini = min(mini, a);
                }
                return mini;
        }
    int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<vector<int>>dp(n, vector<int>(n,-1));
            vector<int>prev(n,0);
            for(int i = 0; i<n; i++){
                    vector<int>curr(n,0);
                    for(int j = 0; j<triangle[i].size(); j++){
                            if(i == 0 && j == 0){
                                    curr[j] = triangle[i][j];
                                    continue;
                            }
                            int diagonal = INT_MAX, down = INT_MAX;
                            if(i>0 && j<triangle[i-1].size()){
                                   down =  triangle[i][j] + prev[j];
                            }
                            if(i>0 && j >0 && j<=triangle[i-1].size()){
                                    diagonal = triangle[i][j] + prev[j-1];
                            }
                            curr[j] = min(diagonal, down);
                    }
                    prev = curr;
            }
            int ans = minimum(prev);
            return ans;
    }
};