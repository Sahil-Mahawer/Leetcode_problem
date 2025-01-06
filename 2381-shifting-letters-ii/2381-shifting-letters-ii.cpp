class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shift) {
        int n = s.size(); // Size of the string

        vector<int> diff(n + 1, 0); // Create a diff array of size n+1 to handle boundary conditions

        // Apply range updates based on the shift queries
        for (int i = 0; i < shift.size(); i++) {
            int start = shift[i][0];
            int end = shift[i][1];
            int direction = shift[i][2];

            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if (end + 1 < n) {
                    diff[end + 1] -= 1;
                }
            } else { // Backward shift
                diff[start] -= 1;
                if (end + 1 < n) {
                    diff[end + 1] += 1;
                }
            }
        }

        // Compute prefix sum
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        // Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26; // Normalize shift to [-25, 25]

            if (shift < 0) {
                shift += 26; // Convert negative shifts to positive
            }

            // Apply the shift to the current character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
        }

        return s;
    }
};
