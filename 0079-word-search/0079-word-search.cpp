class Solution {
public:
int m;
int n;
bool find(int row, int col , int index, vector<vector<char>>& board,  string word )
{
        
        if(index == word.size()){
            return true;
        }


        if(row<0 || col<0 || row>=m || col>=n){
            return false;
        }

        if(board[row][col] != word[index]){
            return false;
        }
        
        char temp = board[row][col];
        board[row][col] = '$';

        bool found = find(row+1, col ,index+1, board, word) || // down
                     find(row-1, col ,index+1, board ,word) || // up
                     find(row , col+1, index+1, board, word) || // right
                     find(row , col-1, index+1, board , word); // left

        board[row][col] = temp;

        return found;

}



    bool exist(vector<vector<char>>& board, string word) {
        
         m = board.size();
         n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == word[0]){

                    if(find(i,j,0 /*index*/, board, word)){    // 0:- index for rach character of word
                        return true;
                    }
                }
            }
 
        }
        return false;
    }
};