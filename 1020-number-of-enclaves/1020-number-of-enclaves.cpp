class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0 || visited[i][j]) return;
        visited[i][j] = 1;
        dfs(i+1, j, m, n, grid, visited);
        dfs(i-1, j, m, n, grid, visited);
        dfs(i, j+1, m, n, grid, visited);
        dfs(i, j-1, m, n, grid, visited);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        /*traversing boundaries*/
        //First row & last row 
        for(int j = 0; j<n; j++){
            if(!visited[0][j] && grid[0][j] == 1) dfs(0, j, m, n, grid, visited);
            if(!visited[m-1][j] && grid[m-1][j] == 1) dfs(m-1, j, m, n, grid, visited);
        }
        //First col & last col
        for(int i = 0; i<m; i++){
            if(!visited[i][0] && grid[i][0] == 1) dfs(i, 0, m, n, grid, visited);
            if(!visited[i][n-1] && grid[i][n-1] == 1) dfs(i, n-1, m, n, grid, visited);
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};