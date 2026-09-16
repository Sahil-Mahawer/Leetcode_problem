class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        //adjacency list
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);

        for(int i=0; i<relations.size(); i++){

            int u = relations[i][0];
            int v = relations[i][1];
            
            // Convert into 0 based indexing
            adj[u-1].push_back(v-1);
            indegree[v-1]++;
        }

        queue<int> que;
        
        // put indegree 0 into queue 
        for(int i=0; i<n; i++){

            if(indegree[i] == 0){
                que.push(i);
            }
        }

        // Maximum time to complete Previous Course
        vector<int> course_time(n,0);

        while(!que.empty()){

            int node = que.front();
            que.pop();

            for(int j=0; j<adj[node].size(); j++){

                indegree[adj[node][j]]--;

                if(indegree[adj[node][j]] == 0)
                que.push(adj[node][j]); 

                // Maximum time to complete previous course + present course time 
                course_time[adj[node][j]] =  max(course_time[adj[node][j]] , course_time[node] + time[node]);

            }
        }

        int ans = 0; 

        for(int i=0; i<n; i++){

            ans = max(ans, course_time[i] + time[i]);
        }

        return ans;
    }
};