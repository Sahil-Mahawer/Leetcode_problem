class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        int row_index = 0;
        int col_index = col-1;

        while(row_index<row && col_index>=0){

            if(matrix[row_index][col_index]==target)
            return 1;

            else if( matrix[row_index][col_index] > target)
                col_index--;

             else
             row_index++;
            
        }
        return 0;
    }
};