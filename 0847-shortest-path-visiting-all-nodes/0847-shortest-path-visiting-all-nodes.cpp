class Solution {
public:

    typedef pair<int,int>P;

    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();

        if(n == 0 || n == 1){
            return 0;
        }

        queue<P> que; // {node, maskValue}
        set<P> visited; // {node, Pathmask}

        //BFS from all nodes
        for(int i=0; i<n; i++){

            int maskValue = (1 << i);

            que.push({i,maskValue});
            visited.insert({i, maskValue});
        }

        int path = 0; 

        int allVisitedState = pow(2,n) - 1;

        while(!que.empty()){

            int size = que.size();

            path++;

            while(size--){

                auto curr = que.front();
                que.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for(int j=0; j<graph[currNode].size(); j++){

                    int nextNode = graph[currNode][j];
                    
                    int nextMask = currMask | (1 << nextNode);  //  both nodes are visited -->> keeping track of path 

                    if(nextMask == allVisitedState) // 1111
                    return path;

                    if(visited.find({nextNode,nextMask}) == visited.end()){

                        que.push({nextNode,nextMask});
                        visited.insert({nextNode,nextMask});
                    }
                }
            }
        }

        return -1;
    }
};