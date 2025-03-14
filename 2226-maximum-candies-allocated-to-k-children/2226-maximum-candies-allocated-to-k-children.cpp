class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int n = candies.size();
        int total_candies = 0;
        int result=0;

        int max_candies = INT_MIN;

        for(int i=0;i<n;i++){
            total_candies += candies[i];

            max_candies = max(max_candies, candies[i]);

        }

        if(total_candies < k){
            return 0;
        }

        int left = 1;
        int right = max_candies;

        while(left <= right){
            int mid = left + (right-left)/2;

            int count = 0;
            for(int i=0;i<n;i++){
                count += candies[i]/mid;

                if(count>=k){
                    break;
                }
            }

            if(count>=k){
                result = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return result;
    }
};