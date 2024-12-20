class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        

        intervals.push_back(newinterval);
        vector<vector<int>> merge;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        for(int i=0;i<n;i++){

            if(merge.empty()){
                merge.push_back(intervals[i]);
            }
            else{
                if(intervals[i][0]<=merge.back()[1]){
                    merge.back()[1]= max(intervals[i][1], merge.back()[1] );
                }
                else{
                    merge.push_back(intervals[i]);
                }
            }
        }
        return merge;


        
    }
};