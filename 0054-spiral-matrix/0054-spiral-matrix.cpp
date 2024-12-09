class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
    
        int row =  arr.size();
        int col =  arr[0].size();

        int total = row*col;
        int count = 0;

        int starting_row = 0;
        int ending_col = col-1;
        int ending_row = row-1;
        int starting_col = 0;

        vector<int>ans;

        while(count<total){

            //print starting row 
            for(int i=starting_col; i<=ending_col && count<total; i++){
                ans.push_back(arr[starting_row][i]);
                count++;
            }
            starting_row++;

            //print ending col
            for(int i =starting_row; i<=ending_row && count<total; i++){
                ans.push_back(arr[i][ending_col]);
                count++;
            }
            ending_col--;

            //print ending row
            for(int i=ending_col; i>=starting_col && count<total; i--){
                ans.push_back(arr[ending_row][i]);
                count++;
            }
            ending_row--;

            //print starting col
            for(int i=ending_row; i>=starting_row && count<total; i--){
                 ans.push_back(arr[i][starting_col]);
                 count++;
            }
            starting_col++;
        }

        return ans;
    }
};