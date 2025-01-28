class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {

        int n = nums.size();
        long long  count = 0;

        

        sort(nums.begin(), nums.end());


        int median = n/2;

        if(nums[median]==k){
            return count;
        }

        if(nums[median] > k){

            for(int i=n/2;i>=0;i--){
                count+= max(0,nums[i]-k);
            }

        }
        else
        {
            for(int i=n/2;i<n;i++){
                count+= max(0 , k-nums[i]);
            }
        }
        return count;
    }
};