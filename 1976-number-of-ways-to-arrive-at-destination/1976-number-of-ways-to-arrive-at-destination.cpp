class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjs(n);
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adjs[u].push_back({v,w});
            adjs[v].push_back({u,w});
        }
        vector<long long>dist(n,LLONG_MAX);
        dist[0] = 0;
        vector<int>ways(n,0);
        ways[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long distace = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distace>dist[node]) continue;
            for(auto [neighbor, edgeWeight]: adjs[node]){
                if(distace+edgeWeight<dist[neighbor]){
                    dist[neighbor] = distace+edgeWeight;
                    ways[neighbor] = ways[node];
                    pq.push({dist[neighbor], neighbor});
                }else if(distace+edgeWeight==dist[neighbor]){
                    ways[neighbor] = (ways[neighbor]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};