class Solution {
public:

bool dfs(int node,vector<vector<int>>& adj,  vector<bool>& path, vector<bool>& visited){

    path[node] = 1;
    visited[node] = 1;

    for(int j=0; j<adj[node].size(); j++){

        if(path[adj[node][j]] == 1){
            return 1;
        }

        if(visited[adj[node][j]] == 1){
            continue;
        }

        if(dfs(adj[node][j], adj, path, visited) == 1)
        return 1;
    }

    path[node] = 0;
    return 0; 
}
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

       int V = adj.size(); 

       vector<bool> path(V, 0);
       vector<bool> visited(V,0);

       

       for(int i=0; i<V; i++){

        if(visited[i] == 0){

            dfs(i, adj, path, visited);
        }
       }
       
       vector<int> safe;

       for(int i=0; i<V; i++){

        if(path[i] == 0){
            safe.push_back(i);
        }
       }

       return safe;

    }
};