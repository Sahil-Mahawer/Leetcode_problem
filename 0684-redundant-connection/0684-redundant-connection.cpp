class Solution {
public:

bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& visited){

    visited[u] = 1;

    if(u == v){
        return 1; 
    }

    for(int i=0; i<adj[u].size(); i++){

        if(visited[adj[u][i]] == 1)
        continue;

       if(dfs(adj, adj[u][i], v, visited) == 1)
       return 1; 
    }

    return 0; 
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++){

            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> visited(n, false);

            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, u, v , visited)){

                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {}; 
    }
};