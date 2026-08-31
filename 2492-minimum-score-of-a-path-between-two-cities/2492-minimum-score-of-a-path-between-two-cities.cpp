class Solution {
public:

void  dfs(unordered_map<int, vector<pair<int,int>>>& adj, vector<bool>& visited, int curr, int& result){

    visited[curr] = true;

    for(int i=0; i<adj[curr].size(); i++){

        int v = adj[curr][i].first;
        int d = adj[curr][i].second;

        result = min(result,d);

        if(visited[v] == false){
            dfs(adj, visited, v, result);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i=0; i<roads.size(); i++){

            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<bool> visited(n,false);

        int result = INT_MAX;

        dfs(adj, visited, 1, result);

        return result;
    }
};