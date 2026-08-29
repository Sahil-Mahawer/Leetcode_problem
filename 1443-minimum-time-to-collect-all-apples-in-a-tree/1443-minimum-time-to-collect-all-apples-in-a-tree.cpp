class Solution {
public:

int dfs( unordered_map<int, vector<int>>& adj, int current, int parent,vector<bool>& hasApple){

    int time = 0;

    for(int i=0; i<adj[current].size(); i++){

        int child = adj[current][i];

        if(child == parent){
            continue;
        }

        int time_from_my_child = dfs(adj, child, current, hasApple);

        if(time_from_my_child >0 || hasApple[child] == true){

            time += time_from_my_child + 2;
        }
    }

    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){

            vector<int> vec = edges[i];

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0 /*current*/, -1 /*parent*/, hasApple);
    }
};