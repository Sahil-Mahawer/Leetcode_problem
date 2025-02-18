class Solution {
public:
    int m, n;          // Grid dimensions
    int result ;    // Stores the number of valid paths
    int non_obstacles; // Total walkable cells (0 + 1)

    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1} };
    void solve(vector<vector<int>>& grid, int i, int j, int count) {
        // Base Case: Out of bounds or on an obstacle
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }

        // If we reach the endpoint (2)
        if (grid[i][j] == 2) {
            // If we visited all non-obstacle cells
            if (count == non_obstacles) {
                result++;  // Valid path found
            }
            return;  // Do NOT backtrack from endpoint
        }

        // Save the current cell value and mark it as visited
        
        grid[i][j] = -1;  // Mark as visited

        // // Explore all 4 possible directions
        // solve(grid, i + 1, j, count + 1); // Down
        // solve(grid, i - 1, j, count + 1); // Up
        // solve(grid, i, j + 1, count + 1); // Right
        // solve(grid, i, j - 1, count + 1); // Left

        for(vector<int> &dir : directions)
        {
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            solve(grid , new_i, new_j, count+1);
        }

        // Backtrack: Restore the grid to its original state
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        result = 0;
        non_obstacles = 0;
        int start_x = 0, start_y = 0;

        // Step 1: Count walkable cells and find the starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 1) {
                    non_obstacles++;  // Count walkable cells (0 + 1)
                }
                if (grid[i][j] == 1) {
                    start_x = i;      // Save the starting position
                    start_y = j;
                }
            }
        }
        
        int count = 0;
        // Step 2: Start DFS traversal
        solve(grid, start_x, start_y, count); // We start with count = 1 (starting point included)

        // Step 3: Return the total valid paths
        return result;
    }
};
