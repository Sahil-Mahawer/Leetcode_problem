class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentSum = nums[0]; // represents maximum sum of a subarray ending at the current index
        int maxSum = nums[0];  //maximum sum we have found so far

        // Kdane Algorithm:-
        //If the sum of the previous subarray is hurting the current element, discard it and start fresh.

        for(int i=1; i<nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};