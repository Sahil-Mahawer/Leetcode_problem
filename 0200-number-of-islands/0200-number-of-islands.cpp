class Solution {
public:

    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    void dfs(int i, int j,vector<vector<char>>& grid){

        if(i<0 || i>=r || j<0 || j>=c || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';

        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();

        int count = 0;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == '1'){

                    dfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};