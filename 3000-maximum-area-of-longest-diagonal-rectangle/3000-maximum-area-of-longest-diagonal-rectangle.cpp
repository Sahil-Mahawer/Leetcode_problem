class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        

        int maxArea = 0;
        int maxDiag = 0;

        for(int i=0; i<dimensions.size(); i++){

            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int diag = l*l + w*w;
            int area = l*w;

            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }

            else if(diag == maxDiag){

                maxArea = max(area, maxArea);
            }
        }

        return maxArea;
    }
};