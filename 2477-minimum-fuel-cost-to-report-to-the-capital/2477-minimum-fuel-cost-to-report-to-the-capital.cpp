class Solution {
public:
    long long dfs(int node, int parent, long long &res, vector<vector<int>>& adjs, int seats){
        int passenger = 0;
        for(auto neighbor: adjs[node]){
            if(neighbor == parent) continue;
            int p = dfs(neighbor, node, res, adjs, seats);
            passenger +=p;
            res += ceil((double)p/seats);
        }
        return passenger+1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int N = roads.size()+1;
        vector<vector<int>>adjs(N);
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }
        long long res = 0;
        dfs(0, -1, res, adjs, seats);
        return res;
    }
};