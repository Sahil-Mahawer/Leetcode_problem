class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);

        int q = queries.size();

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            diff[l] += 1; // Increment the start of the range
            if (r + 1 < n) {
                diff[r + 1] -= 1; // Decrement the position after the range
            }
        }

        int cumulative_sum = 0;

        for (int i = 0; i < n; i++) {
            cumulative_sum += diff[i];
            diff[i] = cumulative_sum; // Store cumulative effect at index i
            nums[i] = nums[i] - diff[i]; // Apply decrement to nums

            if (nums[i] > 0) {
                return false; // If any number is still positive, return false
            }
        }

        return true; // If all elements become zero, return true
    }
};
