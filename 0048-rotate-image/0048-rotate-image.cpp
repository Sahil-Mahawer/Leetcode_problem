class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
          vector<vector<int>>arr(row,vector<int>(col));
        
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j], matrix[j][i]);
                // arr[j][i] = matrix[i][j];
                // swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        //     for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         matrix[i][j] = arr[i][j];
              
        //     }
        // }
        
        for(int i=0;i<row;i++){
            int start = 0, end = col-1;

            while(start<end){
            swap(matrix[i][start], matrix[i][end]);

            start++;
            end--;
            }
        }
    }
};