class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int curr = 0;
        int maxVal = 0;
        int minVal = 0;

        for(int i=0;i<differences.size();i++){

            curr = curr + differences[i];

            maxVal = max(maxVal, curr);
            minVal = min(minVal, curr);

            if((upper-maxVal) - (lower - minVal) + 1 <= 0){
                return 0;
            }
        }

        return (upper-maxVal) - (lower - minVal) + 1;
    }
};