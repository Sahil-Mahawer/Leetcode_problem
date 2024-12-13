class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int  end = 0, ans , mid;

        long long start =0;

        for(int i=0;i<n;i++){

            start = start + piles[i];
            end = max(end, piles[i]);
        }

        start = start/h;

        if(start==0)
        start = 1;

        while(start<=end){

            mid = start+(end-start)/2;

            int total_time = 0;

            for(int i=0;i<n;i++){

                total_time+=piles[i]/mid;

                if(piles[i]%mid)
                total_time++;
            }

            if(total_time<=h){
                ans = mid;
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return  ans;
    }
};