class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int sum = 0;
        int max_sub_sum = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];

            max_sub_sum = max(max_sub_sum, sum);

            if(sum<0){
                sum = 0;
            }
        }

        sum = 0;
        int min_sub_sum = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {

            sum = sum + nums[i];

            min_sub_sum = min(sum, min_sub_sum);

            if(sum>0){
                sum = 0;
            }
        }

        return max(abs(max_sub_sum), abs(min_sub_sum));

    }
};