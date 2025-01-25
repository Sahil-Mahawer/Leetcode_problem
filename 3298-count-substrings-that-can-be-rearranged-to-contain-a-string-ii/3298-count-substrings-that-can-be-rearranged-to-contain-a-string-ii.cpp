class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> freq_map;
        for (int i = 0; i < word2.size(); i++) {
            freq_map[word2[i]]++;
        }

        int i = 0, j = 0;
        int count = 0, current = 0;
        int required = freq_map.size();
        int n = word1.size();
        unordered_map<char, int> window_map;

        while (j < n) {
            char ch = word1[j];

            if (freq_map.find(ch) != freq_map.end()) {
                window_map[ch]++;

                if (window_map[ch] == freq_map[ch]) {
                    current++;
                }
            }

            while (current == required) {
                count += n - j;

                if (freq_map.find(word1[i]) != freq_map.end()) {
                    if (window_map[word1[i]] == freq_map[word1[i]]) {
                        current--;
                    }
                    window_map[word1[i]]--;
                }

                i++;
            }

            j++;
        }

        return count;
    }
};
