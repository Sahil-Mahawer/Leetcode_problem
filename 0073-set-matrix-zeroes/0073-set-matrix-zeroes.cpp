class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        pair<int,int> Zeroposition[row * col];
        int zero_count=0;
        int row_index, col_index;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(matrix[i][j]==0){
                    Zeroposition[zero_count]= make_pair(i,j);
                    zero_count++;
                }

            }

        }

        for(int z=0;z<zero_count;z++){
            row_index = Zeroposition[z].first;
            col_index = Zeroposition[z].second;
        
        for(int k=0;k<col;k++){
            matrix[row_index][k]=0;
        }
        for(int m=0;m<row;m++){
            matrix[m][col_index]=0;
        }
    }

    }
};