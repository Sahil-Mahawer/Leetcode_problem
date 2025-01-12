class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long ans = 0, ans1 = 0;
        
        // Case 1: Insert pattern[0] at the beginning
        string f = pattern[0] + text;
        // Case 2: Insert pattern[1] at the end
        string s = text + pattern[1];
        
        long long  count0 = 0, count1 = 0;
        
        // First case (insert pattern[0] at the beginning)
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == pattern[0]) {
                count0++;  // Count occurrences of pattern[0]
            }

            if (pattern[0] == pattern[1]) {
                // If both characters in the pattern are the same
                ans = (count0 * (count0 - 1)) / 2;
            }
            else if (f[i] == pattern[1]) {
                // When pattern[1] appears, pair it with all pattern[0]s before
                ans = ans + count0;
            }
        }

        // Second case (insert pattern[1] at the end)
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == pattern[1]) {
                count1++;  // Count occurrences of pattern[1]
            }

            if (pattern[0] == pattern[1]) {
                // If both characters in the pattern are the same
                ans1 = (count1 * (count1 - 1)) / 2;
            }
            else if (s[i] == pattern[0]) {
                // When pattern[0] appears, pair it with all pattern[1]s after
                ans1 = ans1 + count1;
            }
        }

        // Return the maximum subsequence count between both cases
        return max(ans, ans1);
    }
};
