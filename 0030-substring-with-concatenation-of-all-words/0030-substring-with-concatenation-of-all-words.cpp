class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int wordCount = words.size();
        if (wordCount == 0) return result;

        int wordLen = words[0].size(); // Length of each word
        int totalLen = wordCount * wordLen; // Total length of concatenation of all words

        if (n < totalLen) return result; // If string is too short, no valid substring

        // Frequency map to store the count of each word in words
        unordered_map<string, int> freqMap;
        for (int i = 0; i < wordCount; i++) {
            freqMap[words[i]]++;
        }

        // Iterate over the string using multiple offsets (0 to wordLen - 1)
        // This handles all possible starting points for valid substrings
        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> windowMap;
            int start = offset, end = offset, count = 0;

            while (end + wordLen <= n) {
                string word = s.substr(end, wordLen); // Get the next word in the window
                end += wordLen;

                if (freqMap.find(word) != freqMap.end()) {
                    windowMap[word]++;
                    if (windowMap[word] <= freqMap[word]) {
                        count++; // Increment count if word appears within allowed frequency
                    } else {
                        // Shrink the window if word appears more than allowed
                        while (windowMap[word] > freqMap[word]) {
                            string leftWord = s.substr(start, wordLen);
                            start += wordLen;
                            if (freqMap.find(leftWord) != freqMap.end()) {
                                if (windowMap[leftWord] <= freqMap[leftWord]) {
                                    count--;
                                }
                                windowMap[leftWord]--;
                            }
                        }
                    }

                    // If all words are found, add the starting index to result
                    if (count == wordCount) {
                        result.push_back(start);
                    }
                } else {
                    // Reset the window if the word is not part of the words array
                    windowMap.clear();
                    count = 0;
                    start = end;
                }
            }
        }

        return result;
    }
};
