class Solution {
public:

void dfs(vector<vector<int>>& heights, int i, int j, int prev_val,vector<vector<bool>>& visited){
    
    if(i<0 || i>=heights.size() || j>=heights[0].size() || j<0){
        return;
    }

    if(visited[i][j] == true){
        return;
    }

    if(heights[i][j] < prev_val){
        return;
    }

    visited[i][j] = true;

    dfs(heights, i-1, j, heights[i][j], visited);
    dfs(heights, i+1, j, heights[i][j], visited);
    dfs(heights, i, j-1, heights[i][j], visited);
    dfs(heights, i, j+1, heights[i][j], visited);


}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>>pacificVisited(m, vector<bool>(n,false));
        vector<vector<bool>>atlanticVisited(m, vector<bool>(n,false));


        for(int j=0; j<n; j++){
            dfs(heights, 0, j, INT_MIN, pacificVisited);  // top
        }
        for(int j=0; j<m; j++){
            dfs(heights, j, 0, INT_MIN, pacificVisited);  // left
        }

        for(int j=0; j<m; j++){
            dfs(heights, j, n-1, INT_MIN, atlanticVisited);  // right
        }
        for(int j=0; j<n; j++){
            dfs(heights, m-1, j, INT_MIN, atlanticVisited);  // bottom
        }
        

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(pacificVisited[i][j] && atlanticVisited[i][j]){

                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};