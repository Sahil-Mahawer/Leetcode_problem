class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
      
    //   ---->>>> Brute Force Approach ---->>>>>
      
        // int n = nums.size();
        // long long result = 0;

        // // Iterate over all possible starting points
        // for (int start = 0; start < n; ++start) {
        //     int count = 0; // Count of indices satisfying nums[i] % modulo == k

        //     // Iterate over all possible ending points
        //     for (int end = start; end < n; ++end) {
        //         if (nums[end] % modulo == k) {
        //             count++;
        //         }

        //         // Check if the current subarray is interesting
        //         if (count % modulo == k) {
        //             result++;
        //         }
        //     }
        // }

        // return result;


        // ----->>>> Optimal approach ---->>>>

        int prefixSum = 0;
        int remainder, n = nums.size();
        long long  count = 0;
        unordered_map<int, int> mpp; // Store the remainder and its frequency

        mpp[0] = 1; // Base case: Initialize for remainder 0

        for (int i = 0; i < n; i++) {
            // Convert nums[i] based on the condition
            if (nums[i] % modulo == k) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }

            // Update prefix sum
            prefixSum += nums[i];
            remainder = prefixSum % modulo;

            // Handle negative remainders
            if (remainder < 0) {
                remainder += modulo;
            }

            // Calculate the required remainder for interesting subarrays
            int requiredRemainder = (remainder - k + modulo) % modulo;

            // If the required remainder is already in the map, add its frequency to count
            if (mpp.find(requiredRemainder) != mpp.end()) {
                count += mpp[requiredRemainder];
            }

            // Update the frequency of the current remainder
            mpp[remainder]++;
        }

        return count;
    }
};