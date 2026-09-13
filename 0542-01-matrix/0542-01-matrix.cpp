class Solution {
public:

    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool isValid(int i, int j){

        if(i>=0 && i<r && j>=0 && j<c){
            return true;
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        r = mat.size();
        c = mat[0].size();

        vector<vector<int>> result(r, vector<int>(c,-1));

        queue<pair<int,int>> que;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(mat[i][j] == 0){
                    que.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        while(!que.empty()){

            int new_i = que.front().first;
            int new_j = que.front().second;
            que.pop();

            for(int k=0; k<4; k++){

                if(isValid(new_i + row[k], new_j + col[k])){

                   if(result[new_i+row[k]][new_j+col[k]] == -1){
                    result[new_i+row[k]][new_j+col[k]] = result[new_i][new_j] + 1;
                    que.push({new_i+row[k], new_j+col[k]});
                   }
                }
            }

        }

        return result;
    }
};