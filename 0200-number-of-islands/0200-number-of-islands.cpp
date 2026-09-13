class Solution {
public:

    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool isValid(int i, int j){

        if(i>=0 && i<r && j>=0 && j<c){
            return true;
        }

        return false;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();

        int count = 0;

        queue<pair<int,int>> que;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == '1'){

                    count++;
                    que.push({i,j});
                    grid[i][j] = '0';

                    while(!que.empty()){

                        int new_i = que.front().first;
                        int new_j = que.front().second;
                        que.pop();

                        for(int k=0; k<4; k++){

                            if(isValid(new_i + row[k], new_j + col[k]) && grid[new_i+row[k]][new_j+col[k]] == '1'){
                                grid[new_i+row[k]][new_j+col[k]] = '0';
                                que.push({new_i+row[k], new_j+col[k]});
                            }
                        }

                    }
                }
            }
        }

        return count;
    }
};