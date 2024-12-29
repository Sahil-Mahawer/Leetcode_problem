class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
          
        // ------>>> Brute Force Approach ----->>>

        // int n = nums.size();
        // long long count=0;

        // for(int i=0;i<n;i++){
        //     long long prefixsum=0;

        //     for(int j=i;j<n;j++){

        //         prefixsum += nums[j];

        //         int len = j-i+1;

        //         if(prefixsum*len<k){
        //             count++;
        //         }

        //     }
        // }
        // return count;


        // ---->>> Optimal Approach ---->>>
        
        int n = nums.size();
        int start = 0;
        int end = 0;
        long long count=0;
        long long prefixsum=0;

        while(end<n){
            
            prefixsum += nums[end];


            while(prefixsum*(end-start+1)>=k && start<=end){

            prefixsum = prefixsum-nums[start];
            start++;

            }

            count = count+ (end-start+1);
            end++;
        }

        return count;

    }
};