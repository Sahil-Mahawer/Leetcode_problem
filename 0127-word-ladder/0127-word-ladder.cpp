#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string,int>> que; // {currentWord, steps}
        que.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!que.empty()) {

           string word = que.front().first;

           int steps = que.front().second;

           que.pop();

            // Try changing each letter
            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    if (temp == endWord) {
                        return steps + 1;
                    }

                    if (wordSet.count(temp) && !visited.count(temp)) {
                        que.push({temp, steps + 1});
                        visited.insert(temp);
                    }
                }
            }
        }

        return 0; // No transformation possible
    }
};
