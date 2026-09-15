class Solution {
public:

    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0, -1, 1};

    bool isValid(int i, int j){

        if(i>=0 && i<r && j>=0 && j<c){
            return true;
        }
        return false;
    }

    void solve(vector<vector<char>>& board) {
        
        r = board.size();
        c = board[0].size();

        queue<pair<int,int>> que;

        //first col
        for(int i=0; i<r; i++){

            if(board[i][0] == 'O'){
                que.push({i,0});
                board[i][0] = 'T';
            }
        }

        // first row 
        for(int j=1; j<c; j++){

            if(board[0][j] == 'O'){
                que.push({0,j});
                board[0][j] = 'T';
            }
        }

        //last row
        for(int j=1; j<c; j++){

            if(board[r-1][j] == 'O'){
                que.push({r-1, j});
                board[r-1][j] = 'T';
            }
        }

        //last col
        for(int i=1; i<r-1; i++){

            if(board[i][c-1] == 'O'){
                que.push({i,c-1});
                board[i][c-1] = 'T';
            }
        }

        while(!que.empty()){

            int new_i = que.front().first;
            int new_j = que.front().second;
            que.pop();

            for(int k=0; k<4; k++){

                if(isValid(new_i+row[k], new_j+col[k])){

                    if(board[new_i+row[k]][new_j+col[k]] == 'O'){
                    board[new_i+row[k]][new_j+col[k]] = 'T';
                    que.push({new_i+row[k], new_j+col[k]});
                    }
                }
            }
        }

        // Replace all O with X
        // Replace all T with O  --> represents which cant be in region because one of its neighbour is at boundary with value = 'O'

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }


    }
};