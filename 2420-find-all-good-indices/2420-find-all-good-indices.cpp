class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();

        // Initialize vectors to store left and right streaks of non-increasing and non-decreasing sequences
        vector<int> left_inc(n, 1);
        vector<int> right_inc(n,1);

        // Fill left_inc array: number of consecutive non-increasing elements before index i
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                left_inc[i] = left_inc[i - 1] + 1;
            } 
        }

        // Fill right_inc array: number of consecutive non-decreasing elements after index i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                right_inc[i] = right_inc[i + 1] + 1;
            } 
        }

        // Now check all indices from k to n-k-1
        for (int i = k; i < n - k; i++) {
            if (left_inc[i - 1] >= k && right_inc[i + 1] >= k) {
                result.push_back(i);  // Add index to result if it satisfies the conditions
            }
        }

        return result;
    }
};
