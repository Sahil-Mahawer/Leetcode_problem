class Solution {
public:
    
    // Recursive function to generate all subsets
    void subsequence(vector<int> &nums, int index, int n, vector<vector<int>> &ans, vector<int> temp) {
        // Base Case: When index reaches the end of the array, store the subset
        if (index == n) {
            ans.push_back(temp);
            return;
        }

        // Case 1: Exclude the current element and move to the next index
        subsequence(nums, index + 1, n, ans, temp);

        // Case 2: Include the current element and move to the next index
        temp.push_back(nums[index]); // Add current element
        subsequence(nums, index + 1, n, ans, temp); // Recur with included element
    }

    // Function to generate all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; // Stores all subsets
        vector<int> temp; // Temporary vector to store a subset
        subsequence(nums, 0, nums.size(), ans, temp); // Call the recursive function
        return ans; // Return the list of all subsets
    }
};
