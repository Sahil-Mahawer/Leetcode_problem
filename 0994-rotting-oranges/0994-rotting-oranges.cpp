class Solution {
public:

    int r;
    int c;

    int orangesRotting(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> que;

        for(int i=0; i<r; i++){
          for(int j=0; j<c; j++){
            if(grid[i][j] == 2){
                que.push({i,j});
            }
          }
        }

         int timer=0; 

         while(!que.empty()){

              timer++;
              int infection = que.size();

              while(infection --){

                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                //up
                if(i-1 >=0){
                    if(grid[i-1][j] == 1){
                        grid[i-1][j] = 2;
                        que.push({i-1,j});
                    }
                }

                //down
                if(i+1 <r){
                    if(grid[i+1][j] == 1){
                        grid[i+1][j] = 2;
                        que.push({i+1,j});
                    }
                }

                 //left
                if(j-1 >=0){
                    if(grid[i][j-1] == 1){
                        grid[i][j-1] = 2;
                        que.push({i,j-1});
                    }
                }

                //right
                if(j+1 <c){
                    if(grid[i][j+1] == 1){
                        grid[i][j+1] = 2;
                        que.push({i,j+1});
                    }
                }

              } 
         }

         for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == 1){
                    return -1;
                }
            }
         }

          if(timer > 0){
            return timer - 1;
          }

          return timer;
    }
};