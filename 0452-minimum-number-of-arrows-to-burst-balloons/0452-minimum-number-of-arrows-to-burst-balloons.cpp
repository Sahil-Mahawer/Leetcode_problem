class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
         int n = points.size();
         sort(points.begin(), points.end());
        //  sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        //  return a[1] < b[1];
        //  });

        if(n==0){
            return 0;
        }

        int last = points[0][1];
        int arrows = 1;
        for(int i=1;i<n;i++){

            if(points[i][0]<=last){
                continue;
            }
            else{
                last = points[i][1];
                arrows++;
            }
        }

        return arrows;

     }
};