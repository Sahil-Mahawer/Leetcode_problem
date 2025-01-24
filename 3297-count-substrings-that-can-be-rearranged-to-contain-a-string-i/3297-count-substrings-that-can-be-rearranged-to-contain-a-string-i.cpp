class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> freqMap, windowMap;
        
        // Count frequencies of characters in word2
        for (int i = 0; i < word2.length(); i++) {
            char ch = word2[i];
            freqMap[ch]++;
        }

        int start = 0, required = freqMap.size(), current = 0;
        long long count = 0;
        

        // Sliding window approach
        for (int end = 0; end < word1.length(); end++) {
            char curr = word1[end];

            // If the character is present in word2, update the windowMap
            if (freqMap.find(curr) != freqMap.end()) {
                windowMap[curr]++;
                
                // Check if the frequency matches
                if (windowMap[curr] == freqMap[curr]) {
                    current++;  // If the character count is exactly required, increment current
                }
            }

            // When the window is valid, count all valid substrings
            while (current == required) {
                count += word1.length() - end;  // Add all valid substrings from start to end

                // Shrink the window from the left
                char pre = word1[start];
                windowMap[pre]--;

                // If the character no longer satisfies the frequency, decrement current
                if (freqMap.find(pre) != freqMap.end() ) {
                    current--;
                }

                start++;
            }
        }

        return count;
    }
};
