class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();

        vector<int> color(v,-1);

        queue<int> q;

        for(int i=0; i<v; i++){

            if(color[i] == -1){
            
                q.push(i);  // push one node into the queue
                color[i] = 0; // assign color to them 

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(int j=0; j<graph[node].size(); j++){

                // if node is not colored 
                if(color[graph[node][j]] == -1){

                    color[graph[node][j]] = (color[node] + 1) % 2; // by this we get the opposite color 
                    q.push(graph[node][j]);
                }

                // if node is already colored
                else{

                    if(color[node] == color[graph[node][j]]){
                        return 0;
                    }
                }
            }
        }

        }
        }
        

        return 1; 


    }
};