class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        vector<int> years(101,0);

        for(int i=0;i<logs.size();i++){

            int by = logs[i][0] - 1950; // mapping with  vector (year) as index starts from zero ... 0 ->1950 , 1 ->1951 , 2 ->1952  and so on
            int dy = logs[i][1] - 1950;
            
            years[by]++;   // increment birth year by 1
            years[dy]--;   // decrement birth year by 1
        }

        int max_population=0;
        int earliest_year = 1950;
        int current_population = 0;

        for(int i=0;i<101;i++){

          current_population += years[i];

            if(current_population > max_population){
                max_population = current_population;
                earliest_year = 1950 + i;
            }

        }

        return earliest_year;
    }
};