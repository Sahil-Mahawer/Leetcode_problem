class Solution {
public:

int m , n;
int peri;

void dfs(vector<vector<int>>& grid, int i, int j)
{

    if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0){

        peri++;
        return;
    }

    if(grid[i][j] == -1){  // agr phle se hee visited hai toh return hojaao
        return;
    }

    grid[i][j] = -1; // mark as visited

    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

    int islandPerimeter(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        peri = 0;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 1){

                    dfs(grid, i, j);
                    return peri;
                }
            }
        }

        return -1;
    }
};