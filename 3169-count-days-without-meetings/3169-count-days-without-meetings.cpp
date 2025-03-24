class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n = meetings.size();

        sort(begin(meetings), end(meetings));
        
        int days_off = 0;
        int start = 0, end =0;

        for(int i=0;i<n;i++){

            start = meetings[i][0];
           
            if(start > end){
                days_off += start-end-1;
            }

            end = max(end, meetings[i][1]); 

        }

         if( end < days){
            days_off += days-end;
         }


         return days_off;


  

  }

 
};