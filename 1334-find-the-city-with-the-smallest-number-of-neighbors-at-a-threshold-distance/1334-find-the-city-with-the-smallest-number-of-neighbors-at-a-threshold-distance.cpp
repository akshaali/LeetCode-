class Solution {
public:
    int bfs(int src, vector<vector<pair<int,int>>>&adjs,int distanceThreshold,int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        int cityReached = -1;
        set<int> visited;
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(!visited.count(node)){
                visited.insert(node);
                for(auto it: adjs[node]){
                int adjacent = it.first;
                int weight = it.second;
                if(weight+dist<= distanceThreshold){
                    pq.push({weight+dist, adjacent});
                }
            }
            }
        }
        return visited.size()-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adjs(n);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjs[u].push_back({v,w});
            adjs[v].push_back({u,w});
        }
        int ans = -1;
        int cities = n;
        for(int i = 0; i<n; i++){
            int neighborsCityReached = bfs(i,adjs,distanceThreshold,n);
            if(neighborsCityReached<=cities){
                cities = neighborsCityReached;
                ans = i;
            }
        }
        return ans;
    }
};