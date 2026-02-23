class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({1, {0,0}});
        while(!pq.empty()){
            int d = pq.front().first;
            int r = pq.front().second.first;
            int c = pq.front().second.second;
            pq.pop();
            for(int dr=-1; dr<=1; dr++){
                for(int dc=-1; dc<=1; dc++){
                    int nrow = r + dr;
                    int ncol = c + dc;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0){
                        if(d + 1 < dist[nrow][ncol]){
                            dist[nrow][ncol] = d + 1;
                            pq.push({dist[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];
    }
};