class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);
        vector<int> indegree(n,0);

        for(int i=0; i<invocations.size(); i++){

            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()){

            int curr = que.front();
            que.pop();

            for(int i=0; i<adj[curr].size(); i++){

                int neighbour = adj[curr][i];

                indegree[neighbour]--;

                if(suspicious[neighbour] == false){
                    que.push(neighbour);
                    suspicious[neighbour] = true;
                }
            }
        }


        vector<int> ans;
        bool cannotRemove = false;

        for(int i=0; i<n; i++){

            if(suspicious[i] == true && indegree[i] >0){
                // we cannot remove
                cannotRemove = true;
                break;

            }

            if(!suspicious[i]){
                ans.push_back(i);
            }
        }

        if(cannotRemove){
            vector<int> vec(n);
            for(int i=0; i<n; i++){
                vec[i]= i;
            }

            return vec;
        }

        return ans;

    }
};