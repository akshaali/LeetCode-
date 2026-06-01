class Solution {
public:
    void dfs1(int node, int parent, vector<int> &path, vector<vector<int>>& adjs){
        path[node] = parent;
        for(auto neighbor: adjs[node]){
            if(neighbor == parent) continue;
            dfs1(neighbor,node,path,adjs);
        }
    }
    void dfs2(int node, int parent, int currTime, vector<int> & time, vector<vector<int>>& adjs){
        time[node] = currTime;
        for(auto neighbor: adjs[node]){
            if(neighbor == parent) continue;
            dfs2(neighbor, node, currTime+1, time, adjs);
        }
    }
    void dfs3(int node, int parent, int currPathProfit, int &ans,vector<int>&profit, vector<vector<int>>& adjs){
        currPathProfit += profit[node];
        bool isLeaf = true;
        for(auto neighbor: adjs[node]){
            if(neighbor == parent) continue;
            isLeaf = false;
            dfs3(neighbor, node, currPathProfit, ans, profit, adjs);
        }
        if(isLeaf) ans = max(ans, currPathProfit);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N = edges.size()+1;
        vector<vector<int>>adjs(N);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }
        vector<int>bobPath(N, -1);
        dfs1(0, -1, bobPath, adjs);
        vector<int>bobTime(N, 1e9);
        int currBobTime = 0;
        int currBobNode = bob;
        while(currBobNode != -1){
            bobTime[currBobNode] = currBobTime;
            currBobNode = bobPath[currBobNode];
            currBobTime++;
        }
        vector<int>aliceTime(N, 1e9);
        dfs2(0, -1, 0, aliceTime, adjs);
        vector<int>profitAlice(N, 0);
        for(int i = 0; i<N; i++){
            if(aliceTime[i]<bobTime[i]) profitAlice[i] = amount[i];
            else if(aliceTime[i] == bobTime[i]) profitAlice[i] = amount[i]/2;
        }
        int ans = INT_MIN;
        dfs3(0, -1, 0, ans, profitAlice, adjs);
        return ans;
    }
};