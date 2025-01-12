class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();

        // If strings are already equal
        if (s1 == s2) {
            return true;
        }

        // Try swapping characters in `s1` to see if it matches `s2`
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s1[i], s1[j]); // Swap characters at positions i and j
                if (s1 == s2) {
                    return true; // Strings match after the swap
                }
                swap(s1[i], s1[j]); // Revert the swap
            }
        }

        // Try swapping characters in `s2` to see if it matches `s1`
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s2[i], s2[j]); // Swap characters at positions i and j
                if (s1 == s2) {
                    return true; // Strings match after the swap
                }
                swap(s2[i], s2[j]); // Revert the swap
            }
        }

        return false; // No single swap can make the strings equal
    }
};
