class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstlist, vector<vector<int>>& secondlist) {
        
         vector<vector<int>> ans;

         int i=0, j=0;

         while(i<firstlist.size() && j<secondlist.size()){
            
            int start = max(firstlist[i][0], secondlist[j][0]);
            int end = min(firstlist[i][1], secondlist[j][1]);
            
            if(start<=end){
                ans.push_back({start,end});
            }

            if(firstlist[i][1]<secondlist[j][1]) // the interval which end first .. move the pointer inward
            i++;

            else{
            j++;
            }
         }
         return ans;

    }
};