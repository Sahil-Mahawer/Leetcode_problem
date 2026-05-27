class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long  start = 1, end = 0, ans = 0, mid;

        int n = piles.size();

        for(int i=0; i<n; i++){
            end = max(end,(long long ) piles[i]);
        }

        while(start <= end){

                long long total_time=0;
             mid = start + (end-start)/2;

             for(int i=0; i<n; i++){
                 total_time += piles[i]/mid;

                 if(piles[i]%mid !=0){  // means remainder is not zero 
                 total_time++; 
                 }
             }

             if(total_time <=h){
                ans = mid;
                end = mid - 1;
             }
             else{
                start = mid + 1; 
             }
        }

        return ans;
    }
};