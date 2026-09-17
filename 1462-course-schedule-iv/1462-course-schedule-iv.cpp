class Solution {
public:

    bool dfs( unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& visited)
    {
        visited[src] = true;

        if(src == dest){
            return true;
        }

        for(int i=0; i<adj[src].size(); i++){

            if(visited[adj[src][i]] == false){

                if(dfs(adj, adj[src][i], dest, visited)){
                    return true;
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);

        }

        int Q = queries.size();
        vector<bool> ans(Q,false);

        for(int i=0; i<Q; i++){

            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(numCourses, 0);

            ans[i] = dfs(adj, u, v, visited);
        }
        
        return ans;
    }
};