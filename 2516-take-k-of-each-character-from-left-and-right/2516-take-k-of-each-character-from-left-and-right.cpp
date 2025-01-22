class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        int count_a = 0, count_b = 0, count_c = 0;

        // Count the total occurrences of 'a', 'b', and 'c' in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                count_a++;
            } else if (s[i] == 'b') {
                count_b++;
            } else if (s[i] == 'c') {
                count_c++;
            }
        }

        // If any character appears less than k times, return -1
        if (count_a < k || count_b < k || count_c < k) {
            return -1;
        }

        // Sliding window to find the largest substring to exclude
        int i = 0, j = 0;
        int not_deleted_Window_size = 0;

        while (j < n) {
            // Decrement the count for the current character (removing from the window)
            if (s[j] == 'a') {
                count_a--;
            } else if (s[j] == 'b') {
                count_b--;
            } else if (s[j] == 'c') {
                count_c--;
            }

            // Shrink the window if any count goes below `k`
            while (i <= j && (count_a < k || count_b < k || count_c < k)) {
                if (s[i] == 'a') {
                    count_a++;  // Restore the count
                } else if (s[i] == 'b') {
                    count_b++;
                } else if (s[i] == 'c') {
                    count_c++;
                }
                i++;  // Move the left pointer
            }

            // Update the maximum window size
            not_deleted_Window_size = max(not_deleted_Window_size, j - i + 1);

            // Move the right pointer
            j++;
        }

        // Minimum time is the total length minus the maximum window size
        return n - not_deleted_Window_size;
    }
};
