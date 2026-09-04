class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){

            int u = prerequisites[i][1];
            int v = prerequisites[i][0]; 

            adj[u].push_back(v);

            indegree[v]++;

        }

        queue<int> que;

        int count = 0;

        for(int i=0; i<numCourses; i++){

            if(indegree[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){

            int node = que.front();
            que.pop();

            count++;

            for(int j=0; j<adj[node].size(); j++){

                indegree[adj[node][j]] --;

                if(indegree[adj[node][j]] == 0){
                    que.push(adj[node][j]);
                }
            }
        }

        if(count == numCourses)
        return true;
        
        return false;
    }
};