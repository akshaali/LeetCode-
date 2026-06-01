class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), passengers(n, 1);
        long long res = 0;

        for (auto& road : roads) {
            int src = road[0], dst = road[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
            indegree[src]++;
            indegree[dst]++;
        }

        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (indegree[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();q.pop();
            res += ceil((double) passengers[node] / seats);
            for (int parent : adj[node]) {
                if (--indegree[parent] == 1 && parent != 0) q.push(parent);
                passengers[parent] += passengers[node];
            }
        }

        return res;
    }
};