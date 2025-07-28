class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(int i=0; i<prerequisites.size(); i++){

            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // b ----> a

            adj[b].push_back(a);

            indegree[a]++;
        }


        queue<int> q;

        int count = 0;

        for(int i=0; i<numCourses; i++){

            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){

            int node = q.front(); 
            q.pop();

            count++;

            for(int i=0; i<adj[node].size(); i++){

                indegree[adj[node][i]]--;

                if(indegree[adj[node][i]] == 0){

                    q.push(adj[node][i]);
                }
            }
        }

        if(count == numCourses){
            return true;
        }
        
        return false;
    }
};