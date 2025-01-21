class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int col = grid[0].size();
        long long first_row_remaining = accumulate(grid[0].begin(), grid[0].end(), 0LL);

        long long second_row_remaining = 0;

        long long minimized_result = LONG_LONG_MAX;

        for(int robot1col = 0; robot1col<col; robot1col++){
            
            // Robot1 take this strategy
            first_row_remaining -= grid[0][robot1col];

            // Robot2 will try take best after robot1 take above strategy
            long long best_of_robot2 = max(first_row_remaining, second_row_remaining);

            minimized_result = min( minimized_result , best_of_robot2);

            second_row_remaining += grid[1][robot1col]; 

        }

        return minimized_result;

    }
};