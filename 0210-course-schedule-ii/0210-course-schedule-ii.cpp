class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<int> result;

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);


        for(int i=0; i<prerequisites.size(); i++){

            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // b ---> a 
            adj[b].push_back(a);

            indegree[a]++;
        }

        queue<int> q; 

        for(int i=0; i<numCourses; i++){

            if(indegree[i] == 0){

                result.push_back(i);

                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){

            int node = q.front();

            q.pop();

            count++;

            for(int i=0; i<adj[node].size(); i++){

                int neighbour = adj[node][i];

                indegree[neighbour]--;

                if(indegree[neighbour] == 0){

                    result.push_back(neighbour);

                    q.push(neighbour);
                }
            }
        }

        if(count == numCourses){
            return result;
        }

        return {};
    }
};