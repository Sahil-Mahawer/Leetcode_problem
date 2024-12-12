class Solution {
public:
    int majorityElement(vector<int>& arr) {
        
        int candidate, count = 0;
        int n = arr.size();
        
        // Phase 1: Finding the candidate for the majority element
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            } else if (candidate == arr[i]) {
                count++;
            } else {
                count--;
            }
        }

        // Phase 2: Verify if the candidate is actually the majority element
        count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate) {
                count++;
            }
        }

        if (count > n / 2) {
            return candidate; // The majority element
        }
        
        // In case no majority element exists (not possible as per problem constraints)
        return -1;
    }
};
