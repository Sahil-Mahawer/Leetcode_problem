class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();

        int min_row = m;
        int max_row = -1;

        int min_col = n;
        int max_col = -1;


        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 1){

                    min_row = min(min_row, i);
                    max_row = max(max_row, i);

                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }


        int length = (max_col - min_col + 1);
        int width =  (max_row - min_row + 1);

        return length * width;  
    }
};