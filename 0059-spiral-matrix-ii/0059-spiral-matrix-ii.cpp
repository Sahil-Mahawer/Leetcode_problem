class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
       
        // Initialize an n x n matrix with zeros
        vector<vector<int>> arr(n, vector<int>(n, 0));

        int total = n * n; // Total numbers to fill
        int count = 1;     // Start filling from 1

        int starting_row = 0;
        int ending_row = n - 1;
        int starting_col = 0;
        int ending_col = n - 1;

        while (count <= total) {
            // Fill starting row (left to right)
            for (int i = starting_col; i <= ending_col && count <= total; i++) {
                arr[starting_row][i] = count++;
            }
            starting_row++;

            // Fill ending column (top to bottom)
            for (int i = starting_row; i <= ending_row && count <= total; i++) {
                arr[i][ending_col] = count++;
            }
            ending_col--;

            // Fill ending row (right to left)
            for (int i = ending_col; i >= starting_col && count <= total; i--) {
                arr[ending_row][i] = count++;
            }
            ending_row--;

            // Fill starting column (bottom to top)
            for (int i = ending_row; i >= starting_row && count <= total; i--) {
                arr[i][starting_col] = count++;
            }
            starting_col++;
        }

        return arr;
    
    }
};