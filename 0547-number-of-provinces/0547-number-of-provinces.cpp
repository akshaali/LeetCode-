class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& visited){
        visited[node] = 1;
        for(int it: adjls[node]){
            if(!visited[it]) dfs(it, adjls, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>>adjls(v);
        //converting adjacency matrix to adjacency list
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        //Print adjacency list
        // for(int i = 0; i<v; i++){
        //     cout<<i<<": {";
        //     for(int j = 0; j<adjls[i].size(); j++){
        //         cout<<adjls[i][j]<<",";
        //     }
        //     cout<<"}"<<endl;
        // }
        vector<int>visited(v,0);
        int ans = 0;
        for(int i = 0; i<v; i++){
            if(!visited[i]){
                ans++;
                dfs(i, adjls, visited);
            }
        }
        return ans;
    }
};