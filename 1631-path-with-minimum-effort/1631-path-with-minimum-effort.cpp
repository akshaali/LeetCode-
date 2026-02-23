class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r == m-1 && c == n-1) return d;
            for (int i = 0; i < 4; i++){
                    int nrow = r + dr[i];
                    int ncol = c + dc[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                        int newEffort = max(abs(heights[nrow][ncol] - heights[r][c]), d);
                        if(newEffort < dist[nrow][ncol]){
                            dist[nrow][ncol] = newEffort;
                            pq.push({newEffort, {nrow, ncol}});
                        }
                    }
                }
        }
        return 0;
    }
};