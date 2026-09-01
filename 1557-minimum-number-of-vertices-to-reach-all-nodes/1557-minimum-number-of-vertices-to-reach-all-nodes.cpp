class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<bool> indegree(n,false);
        vector<int> result;
        
        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            // u ---> v (indegree)
            indegree[v] = true;
        }

        for(int i=0; i<n; i++){

            if(indegree[i] == false){
                result.push_back(i);
            }
        }

        return result;
    }
};