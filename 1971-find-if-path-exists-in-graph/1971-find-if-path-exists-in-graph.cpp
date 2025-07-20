class Solution {
public:

bool dfs(vector<vector<int>> &adj, int node, int destination, vector<bool> &visited){

    if(node == destination){
        return true;
    }

    visited[node] = true;

    for(int j = 0; j<adj[node].size(); j++){
        
        if(visited[adj[node][j]] == false){
            
      if(dfs(adj, adj[node][j], destination, visited) == true){

        return true;

      }
        }
    }

    return false;
}


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,0);

        return dfs(adj, source, destination,visited);
    }
};