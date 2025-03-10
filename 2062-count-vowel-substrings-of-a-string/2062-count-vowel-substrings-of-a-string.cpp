class Solution {
public:
    bool is_vowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int countVowelSubstrings(string word) {
        int count = 0;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            
            for (int j = i; j < n; j++) {
                if (is_vowel(word[j])) {
                    mp[word[j]]++;

                    // If all 5 vowels are present, count this substring
                    if (mp.size() == 5) {
                        count++;
                    }
                } else {
                    // Stop expanding if a non-vowel is encountered
                    break;
                }
            }
        }

        return count;
    }
};
