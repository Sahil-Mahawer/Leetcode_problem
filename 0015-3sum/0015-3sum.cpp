class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Edge case: if there are less than 3 elements, no triplet can be formed
        if (n < 3) {
            return result;
        }

        // Step 1: Sort the array to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Step 2: Iterate over the array for the first element nums[i]
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Calculate the target sum for the remaining two elements
            int find1 = 0 - nums[i];
            int start = i + 1;
            int end = n - 1;

            // Step 3: Apply two-pointer approach to find two elements that sum up to find1
            while (start < end) {
                if (nums[start] + nums[end] == find1) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[start], nums[end]});

                    // Skip duplicates for the second and third elements
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;

                    // Move the pointers inward
                    start++;
                    end--;
                } 
                else if (nums[start] + nums[end] < find1) {
                    start++; // We need a larger sum, so move `start` right
                } 
                else {
                    end--; // We need a smaller sum, so move `end` left
                }
            }
        }

        return result;
    }
};
