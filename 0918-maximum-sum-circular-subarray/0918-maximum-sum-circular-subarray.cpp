class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total_sum = 0;
        int sum = 0;
        int max_sub_sum = INT_MIN;

        for(int i=0;i<nums.size();i++){
            total_sum += nums[i];
        }

        for(int i=0;i<nums.size();i++){
           sum = sum + nums[i];
           
           max_sub_sum = max(max_sub_sum, sum);

           if(sum<0){
            sum = 0;
           }
        }

        sum  = 0;
        int min_sub_sum = INT_MAX;

        for(int i=0;i<nums.size();i++){
           sum = sum + nums[i];
           
           min_sub_sum = min(min_sub_sum, sum);

           if(sum>0){
            sum = 0;
           }
        }

        int circular_Subarray_Sum = total_sum - min_sub_sum;

        if (total_sum == min_sub_sum) return max_sub_sum;

        return max(max_sub_sum, circular_Subarray_Sum);

    }
};