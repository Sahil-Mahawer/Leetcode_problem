class Solution {
public:
int n;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v){

    visited[v] = true;

    for(int i=0; i<adj[v].size(); i++){

        int neighbour = adj[v][i]; 

        if(visited[neighbour] == false){

            dfs(adj, visited, neighbour);
        }
    } 
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);

        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){

            for(int j=0; j<n;j++){

                if(isConnected[i][j] == 1){

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0; 

        for(int i=0; i<n; i++){

            if(visited[i] == false){

                dfs(adj, visited, i);
                
                count++;
            }
        }

        return count;
    }
};