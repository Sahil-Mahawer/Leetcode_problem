class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        // Create a vector to store population changes for each year from 1950 to 2050
        // (size 101 because 2050 - 1950 + 1 = 101)
        vector<int> years(101, 0);

        // Loop through each log entry
        for (int i = 0; i < logs.size(); i++) {

            // Calculate the index corresponding to the birth year
            int by = logs[i][0] - 1950; // Map 1950 to index 0, 1951 to index 1, and so on

            // Calculate the index corresponding to the death year
            int dy = logs[i][1] - 1950; // Map 2050 to index 100

            // Increment the population for the birth year
            years[by]++;

            // Decrement the population for the year after death
            // (since population count includes the birth year but excludes the death year)
            years[dy]--;
        }

        // Variables to track the maximum population and the corresponding earliest year
        int max_population = 0;  // Stores the maximum population encountered
        int earliest_year = 1950; // Initialize to the first year in the range
        int current_population = 0; // Tracks the cumulative population as we iterate

        // Iterate over all years from 1950 to 2050
        for (int i = 0; i < 101; i++) {

            // Update the current population using the difference array
            current_population += years[i];

            // If the current population exceeds the maximum population found so far
            if (current_population > max_population) {
                max_population = current_population; // Update the maximum population
                earliest_year = 1950 + i; // Map the index back to the corresponding year
            }
        }

        // Return the earliest year with the maximum population
        return earliest_year;
    }
};
