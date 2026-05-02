class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 0));
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<pair<int, int>, int>>que;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    que.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int>dr = {-1, 0, 1, 0};
        vector<int>dc = {0, 1, 0, -1};
        while(!que.empty()){
            int row = que.front().first.first;
            int col = que.front().first.second;
            int step = que.front().second;
            que.pop();
            distance[row][col] = step;
            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    que.push({{nrow, ncol}, step+1});
                }
            }
        }
        return distance;
    }
};