//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
using namespace std;
class Solution{
    public:
    void solve(vector<string> &ans, string path,vector<vector<int>> &travelled, int col, int row, vector<vector<int>>matrix, int n){
        // cout<<col<<" "<<row<<endl;
        if(col == n-1 && row == n-1){
            ans.push_back(path);
            return;
        }
        //down
        if(row+1<n && travelled[row+1][col] == 0 && matrix[row+1][col] == 1){
            travelled[row][col] = 1;
            // path += 'D';
            solve(ans, path + 'D', travelled, col, row+1, matrix, n);
            // path.pop_back();
            travelled[row][col] = 0;
        }
        //left
        if(col-1>=0 && travelled[row][col-1] == 0 && matrix[row][col-1] == 1){
            travelled[row][col] = 1;
            // path += 'L';
            solve(ans, path + 'L', travelled, col-1, row, matrix, n);
            // path.pop_back();
            travelled[row][col] = 0;
        }
        //right
        if(col+1<n && travelled[row][col+1] == 0 && matrix[row][col+1] ==1){
            travelled[row][col] = 1;
            // path += 'R';
            solve(ans, path + 'R', travelled, col+1, row, matrix, n);
            // path.pop_back();
            travelled[row][col] = 0;
        }
        //up
        if(row-1>=0 && travelled[row-1][col] == 0 && matrix[row-1][col] == 1){
            travelled[row][col] = 1;
            // path += 'U';
            solve(ans, path + 'U', travelled, col, row-1, matrix, n);
            // path.pop_back();
            travelled[row][col] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        vector<string> ans;
        string path;
        vector<vector<int>> travelled(n, vector<int>(n,0));
        if(matrix[0][0] == 1)solve(ans, path,travelled, 0, 0,matrix, n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends