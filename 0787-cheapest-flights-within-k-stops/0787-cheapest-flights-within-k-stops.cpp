class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjs(n);
        for(int i = 0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adjs[u].push_back({v,w});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,src}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        int ans = 1e9;
        while(!pq.empty()){
            auto [stop,details] = pq.top();
            auto [cost, node] = details;
            pq.pop();
            if(stop>k) continue;
            for(auto it: adjs[node]){
                auto [adjacentCity, adjacentCityPrice] = it;
                if(dist[adjacentCity]> cost+adjacentCityPrice){
                    dist[adjacentCity]= cost+adjacentCityPrice;
                    pq.push({stop+1, {dist[adjacentCity], adjacentCity}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};