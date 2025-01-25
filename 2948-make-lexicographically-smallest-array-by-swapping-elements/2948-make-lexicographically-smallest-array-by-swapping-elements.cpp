#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); // Sort the numbers to facilitate grouping

        int group_number = 0;
        unordered_map<int, int> num_To_group; // Map from number to its group
        num_To_group[vec[0]] = group_number; // First number in the sorted array belongs to group 0

        unordered_map<int, list<int>> group_mai_element; // Group -> List of elements

        // Initialize the first group with the first element in the sorted array
        group_mai_element[group_number].push_back(vec[0]);

        // Group the numbers based on the limit
        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                group_number += 1; // Create a new group if the difference exceeds the limit
            }
            num_To_group[vec[i]] = group_number; // Assign the current number to the group
            group_mai_element[group_number].push_back(vec[i]); // Add the number to the appropriate group
        }

        // Build the result array
        vector<int> result(n);

        // Traverse the original `nums` array
        for (int i = 0; i < n; i++) {
            int number = nums[i];
            int group = num_To_group[number];

            // Find the smallest number in the group and place it in the result array
            result[i] = *group_mai_element[group].begin(); // Get the first element in the group (which is the smallest)
            group_mai_element[group].erase(group_mai_element[group].begin()); // Remove the smallest element
        }

        return result;
    }
};
