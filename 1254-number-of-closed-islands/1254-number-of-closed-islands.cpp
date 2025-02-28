class Solution {
public:
int m ,n;

bool solve(vector<vector<int>> &grid, int r, int c){

    if(r>=m || r<0 || c>=n || c<0){
        return false;
    }

    if(grid[r][c] == 1){  // water
        return true;   // closed hai iss side se
    }

    grid[r][c] = 1;

    bool up = solve(grid, r-1, c);
    bool down = solve(grid, r+1,c);
    bool left = solve(grid, r, c-1);
    bool right = solve(grid, r, c+1);

    return up && down && left && right;
}
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                
                if(grid[i][j] == 0){

                    if(solve(grid,i,j) == true){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};