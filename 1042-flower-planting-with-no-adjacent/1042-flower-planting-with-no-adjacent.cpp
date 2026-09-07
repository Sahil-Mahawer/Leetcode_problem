class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        unordered_map<int, vector<int>>adj;

        for(int i=0; i<paths.size(); i++){

            int u = paths[i][0];
            int v = paths[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // // flower[i] = flower assigned to garden i
       vector<int> assignedFlower(n+1, 0);

       for(int garden = 1; garden<=n; garden++){

        bool used[5] = {false};

        for(int j=0; j<adj[garden].size(); j++){

            int ngbr = adj[garden][j];

            if(assignedFlower[ngbr] != 0){
                used[assignedFlower[ngbr]] = true;
            }
        }

        for(int f = 1; f<=4; f++){

            if(used[f] == false){
                assignedFlower[garden] = f;
                break;
            }
        }
       }

       vector<int> result;

       for(int i = 1; i<=n; i++){

        result.push_back(assignedFlower[i]);
       }

       return result;
    }
};