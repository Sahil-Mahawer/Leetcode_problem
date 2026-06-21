class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});

        sort(begin(restrictions), end(restrictions));

        int N = restrictions.size();

        // Left to Right
        for(int i=1; i<N; i++){

            int diff_Of_Distance = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1] , diff_Of_Distance + restrictions[i-1][1]);
        }

        //Right to Left
        for(int i=N-2; i>=0; i--){

            int diff_Of_Distance = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], diff_Of_Distance + restrictions[i+1][1]);
        }

        int result = 0;

        for(int i=1; i<N; i++){

            int leftPos = restrictions[i-1][0];
            int currPos = restrictions[i][0];

            int leftHeight = restrictions[i-1][1];
            int currHeight = restrictions[i][1];

            int height_difference = abs(currHeight - leftHeight);
            int distance_difference = currPos - leftPos;

            int peak = max(leftHeight, currHeight) + (distance_difference - height_difference)/2;

            result = max(peak, result);
        }

        return result;
    }
};