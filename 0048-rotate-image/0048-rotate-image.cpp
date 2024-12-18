class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i=0;i<r-1;i++){
            for(int j=i+1;j<c;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        
        

        
            for(int i=0;i<r;i++){

                int start = 0 , end = c-1;
                while(start<end){
                    swap(matrix[i][start],matrix[i][end]);
                    start++;
                    end--;
                }
            }
        
 
    }
};