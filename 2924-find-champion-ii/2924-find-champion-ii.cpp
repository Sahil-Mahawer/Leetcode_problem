class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;
        }

        int champion = -1;

        for(int i=0; i<n; i++){

            if(indegree[i] == 0){

                if(champion != -1){
                    return -1;
                }

                champion = i;
            }

        }

        return champion;
    }
};