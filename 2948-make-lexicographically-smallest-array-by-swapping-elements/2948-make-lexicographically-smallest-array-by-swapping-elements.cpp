class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
          int n = nums.size();
        
        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if nums[i] and nums[j] can be swapped
                if (abs(nums[i] - nums[j]) <= limit && nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                    // Backtrack to recheck the array up to the current index
                    i = max(-1, i - 2); // Move back to account for cascading swaps
                    break; // Restart inner loop from the updated index
                }
            }
        }
        
        return nums;
    }
};