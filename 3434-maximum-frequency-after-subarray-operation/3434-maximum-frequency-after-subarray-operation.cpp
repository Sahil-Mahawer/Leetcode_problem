class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        int maxFreq = 0; // Variable to store the maximum frequency of k
        int currentKCount = 0; // Count of 'k' in the array

        // Count the initial occurrences of k in the array
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == k) {
                currentKCount++;
            }
        }

        // Initialize the result with the initial count of k
        maxFreq = currentKCount;

        // Iterate over all possible values of 'i' (1 to 50, as given in constraints)
        for (int i = 1; i <= 50; i++) {
            if (i == k) {
                continue; // Skip if i is equal to k, as there's no need to transform k into itself
            }

            int balance = 0; // Keeps track of the balanced transformation
            int maxBalance = 0; // Tracks the maximum balance for the current i

            // Iterate over the array to simulate a sliding window for transforming 'i' into 'k'
            for (int index = 0; index < nums.size(); index++) {
                if (nums[index] == i) {
                    balance++; // Increment balance since transforming i to k increases k's count
                } else if (nums[index] == k) {
                    balance--; // Decrement balance since k already exists and doesn't need transformation
                }  
                // Ignore the number which are neither 'k' or 'i' as they donot contribute


                
                if(balance<0){ // reset balance to 0 if it becomes negative 
                    balance = 0;
                }


                // Keep track of the maximum balance in the subarray
                if (balance > maxBalance) {
                    maxBalance = balance;
                }
            }

            // Update the global maximum frequency
            if (currentKCount + maxBalance > maxFreq) {
                maxFreq = currentKCount + maxBalance;
            }
        }

        return maxFreq;
    }
};
