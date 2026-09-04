class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ans;

        queue<int> que;

        vector<int> indegree(numCourses, 0);

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){

            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        for(int i=0; i<numCourses; i++){

            if(indegree[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){

            int node = que.front();
            que.pop();
            ans.push_back(node);

            for(int j=0; j<adj[node].size(); j++){

                indegree[adj[node][j]]--;

                if(indegree[adj[node][j]] == 0){
                    que.push(adj[node][j]);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        }

        return ans;
    }
};