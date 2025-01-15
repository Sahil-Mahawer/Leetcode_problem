class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxi = INT_MIN;

        // Case 1: If k == 1
        if (k == 1) {
            return (nums.size() > 1) ? nums[1] : -1;
        }

        // Case 2: If array has only one element and k is odd
        if (nums.size() == 1 && k % 2 == 1) {
            return -1;
        }

        // Case 3: If k > nums.size(), remove all elements
        if (k > nums.size()) {
            for (int i = 0; i < nums.size(); i++) {
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        // Case 4: If k == nums.size(), find the maximum of first k-1 elements
        if (k == nums.size()) {
            for (int i = 0; i < k - 1; i++) {
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        // Case 5: If k < nums.size(), consider the maximum of first k-1 elements and nums[k]
        for (int i = 0; i < k - 1; i++) {
            maxi = max(maxi, nums[i]);
        }
        return max(maxi, nums[k]);
    }
};
