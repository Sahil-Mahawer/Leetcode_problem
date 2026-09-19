class Solution {
public:

    int r;
    int c;

    int row[8] = {-1,-1,-1,0,0,1,1,1};
    int col[8] = {-1,0,1,-1,1,-1,0,1};

    bool isValid(int i, int j){

       return i>=0 && i<r && j>=0 && j<c; 
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();

        if(grid[0][0] == 1 || grid[r-1][c-1] == 1){
            return -1;
        }

        queue<pair<int,int>> que;

        que.push({0,0});
        grid[0][0] = 1;

        int level = 0;

        while(!que.empty()){

            int N = que.size();

            while(N--){

                int new_i = que.front().first;
                int new_j = que.front().second;
                que.pop();

                if(new_i == r-1 && new_j == c-1){
                    return level+1;
                }

                for(int k=0; k<8; k++){

                    if(isValid(new_i+row[k], new_j+col[k])){

                        if(grid[new_i+row[k]][new_j+col[k]] == 0){
                            que.push({new_i+row[k], new_j+col[k]});
                            grid[new_i+row[k]][new_j+col[k]] = 1;
                        }
                    }
                }

            }
            level++;
        }

        return -1;
        
    }
};