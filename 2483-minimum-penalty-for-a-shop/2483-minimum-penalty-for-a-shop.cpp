class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int totalY = 0; // Total count of 'Y' in the string
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }

        int before_penalty = 0;    // Penalty for 'N' before the current index
        int after_penalty = totalY; // Penalty for 'Y' after the current index

        int total_penalty = INT_MAX; // Minimum penalty found so far
        int index = -1;             // Best closing time index

        for (int j = 0; j <= n; j++) {
            // Update total penalty for the current index
            int current_penalty = before_penalty + after_penalty;

            // Update minimum penalty and best index if a better one is found
            if (current_penalty < total_penalty) {
                total_penalty = current_penalty;
                index = j;
            }

            // Update penalties for the next index
            if (j < n) {
                if (customers[j] == 'N') before_penalty++; // Increment for 'N'
                if (customers[j] == 'Y') after_penalty--;  // Decrement for 'Y'
            }
        }

        return index; // Return the best closing time
    }
};
