class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);

        for(int i=0; i<dislikes.size(); i++){

            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);

        queue<int> q;

        for(int i=1; i<=n; i++){

            if(color[i] == -1){

                color[i] = 0;
                q.push(i);
            }

            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(int j=0; j<adj[node].size(); j++){

                    if(color[adj[node][j]] == -1){

                        color[adj[node][j]] = (color[node]+1) % 2;
                        q.push(adj[node][j]);
                    }

                    else{

                        if(color[node] == color[adj[node][j]]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};