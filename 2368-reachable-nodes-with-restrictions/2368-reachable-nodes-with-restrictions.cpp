class Solution {
public:

    void dfs(int node, unordered_map<int , vector<int>>& adj, vector<int>& res, vector<int>& visited, int& count)
    {

        if(res[node] == 1){
            return; 
        }

        count++;
        visited[node] = 1;

        for(int j=0; j<adj[node].size(); j++){

            int ngbr = adj[node][j];
            if(visited[ngbr] == 0){
                dfs(adj[node][j], adj, res, visited, count);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        int count = 0;

        unordered_map<int , vector<int>> adj;

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> res(n,0);

        for(int i=0; i<restricted.size(); i++)
        {
            res[restricted[i]] = 1;
        }

        vector<int> visited(n,0);

        dfs(0, adj, res, visited, count);

        return count;
    }
};