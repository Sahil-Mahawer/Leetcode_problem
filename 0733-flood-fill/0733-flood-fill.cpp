class Solution {
public:

void dfs(vector<vector<int>>& image, int i, int j, int old_color, int color, int m, int n){

        if(i<0 || j<0 || i>=m || j>= n){

            return; 
        }

        if(image[i][j]!= old_color){
            return;
        }

        // change color
        image[i][j] = color;

       // Move in 4 directions
        dfs(image, i + 1, j, old_color, color, m, n);
        dfs(image, i - 1, j, old_color,  color, m, n);
        dfs(image, i, j + 1, old_color,  color, m, n);
        dfs(image, i, j - 1, old_color,  color, m, n);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int m = image.size(); 
        int n = image[0].size();

        int old_color = image[sr][sc];

        if(old_color == color){
            return image;
        }

        dfs(image,sr, sc, old_color, color ,m, n);

        return image;
    }
};