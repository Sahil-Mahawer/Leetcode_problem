class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        // ------>>>> Brute force ----->>>>
        
        // long long prefixsum_left=0, prefixsum_right = 0, count=0;
        // int n  = nums.size();

        // for(int i=0;i<n-1;i++){

        //     prefixsum_left+=nums[i];

        //     for(int j=i+1;j<n;j++){

        //         prefixsum_right += nums[j];
        //     }
            
        //     if(prefixsum_left>=prefixsum_right){
        //         count++;
        //     }

        //     prefixsum_right = 0;

        // }
        // return count;


        // ------->>>>> Optimal Approach ----->>>>

        long long total_sum = 0, prefixsum_left = 0, prefixsum_right = 0, count=0;

        int n = nums.size();

        for(int i=0;i<n;i++){

            total_sum += nums[i]; 
        }

        for(int i=0;i<n-1;i++){
             prefixsum_left += nums[i];

             prefixsum_right = total_sum - prefixsum_left;

             if(prefixsum_left>=prefixsum_right){
                count++;
             } 
        }

        return count;
    }
};