class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Edge case: can't even leave start
        if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        vector<int> offset = {1, 0, -1, 0, 1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();
            cout<<"r: "<<r<<" c: "<<c<<" time: "<<time<<endl;
            if (r == m-1 && c == n-1) return time;

            if (time > dist[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + offset[k];
                int nc = c + offset[k+1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int newTime = time + 1;
                if (newTime < grid[nr][nc]) {
                    int diff = grid[nr][nc] - newTime;

                    if (diff % 2 == 0) {
                        newTime = grid[nr][nc];
                    } else {
                        newTime = grid[nr][nc] + 1;
                    }
                }

                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return dist[m-1][n-1];
    }
};