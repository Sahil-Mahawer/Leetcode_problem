class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int start = 0, end = 0, n = nums.size(), count = 0;
        long long max_sum = 0, sum = 0;
        map<int, int> freq; // Map to store frequency of elements

        while (end < n) {
            // Add nums[end] to the window
            sum += nums[end];
            freq[nums[end]]++;  // Increment frequency of nums[end]
            count++;  // Increment element count in the window

            // Shrink the window if the size exceeds `k`
            while (count > k) {
                sum -= nums[start];
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);  // Remove element if its frequency is zero
                }
                start++;  // Move the start pointer to the right
                count--;  // Decrease the element count in the window
            }

            // Check if the window is valid (contains exactly `k` elements and at least `m` distinct elements)
            if (count == k && freq.size() >= m) {
                max_sum = max(max_sum, sum);  // Update the maximum sum
            }

            end++;  // Expand the window by moving `end` forward
        }

        return max_sum;
    }
};