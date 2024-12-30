class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();

       
        long long  subarray_count=0;
        long long  zero_count=0;
        
        for(int i=0;i<n;i++){

            if(nums[i]==0){
                zero_count++;
                subarray_count = subarray_count + zero_count;
            }
            else
            {
                zero_count=0;
            }
        }

        return subarray_count;
    }
};