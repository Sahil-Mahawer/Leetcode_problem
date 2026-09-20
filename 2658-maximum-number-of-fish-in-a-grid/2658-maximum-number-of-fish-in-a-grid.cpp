class Solution {
public:
    int r;
    int c;

    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    void dfs(int ro, int co, vector<vector<int>>& grid, int& sum) {

        if (ro < 0 || ro >= r || co < 0 || co >= c) {
            return;
        }

        if (grid[ro][co] == 0) {

            return;
        }

        sum += grid[ro][co];
        grid[ro][co] = 0;

        for (int k = 0; k < 4; k++) {

            int next_i = ro + row[k];
            int next_j = co + col[k];

            if (next_i >= 0 && next_i < r && next_j >= 0 && next_j < c) {
                if (grid[next_i][next_j] > 0) {
                    dfs(next_i, next_j, grid, sum);
                }
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {

        r = grid.size();
        c = grid[0].size();

        int ans = 0;

        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {

                int sum = 0;

                    if (grid[i][j] > 0) {

                    dfs(i, j, grid, sum);

                    ans = max(sum, ans);
                }
            }
        }

        return ans;
    }
};