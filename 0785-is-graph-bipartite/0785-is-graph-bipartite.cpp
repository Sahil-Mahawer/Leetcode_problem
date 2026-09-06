class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();

        vector<int> color(V,-1);

        queue<int> que;


        for(int i=0; i<V; i++){

            if(color[i] == -1){
                color[i] = 0;
                que.push(i);
            }

            while(!que.empty()){

                int node = que.front();
                que.pop();

                for(int j=0; j<graph[node].size();j++){
                     
                     // if node is not colored 
                     if(color[graph[node][j]] == -1){
                        color[graph[node][j]] = (color[node]+1) % 2;
                        que.push(graph[node][j]);
                     }

                     else{

                        if(color[node] == color[graph[node][j]]){
                            return 0; 
                        }
                     }
                }
            }
        }

        return 1;

    }
};