class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> word_set(wordList.begin(), wordList.end());

        queue<pair<string,int>> que;  // {words,steps)

        que.push({beginWord,1}); 

        word_set.erase(beginWord); // and now start ereasing the words from set which you are getting because there is no point of getting back to that word 

        while(!que.empty()){

            string word = que.front().first;
            int steps = que.front().second;

            for(int i=0; i<word.size(); i++){

                string temp = word;

                for(char ch = 'a'; ch<='z'; ch++){

                    temp[i] = ch;

                    if(temp == endWord){

                        return steps+1;

                    }

                    if(word_set.find(temp) != word_set.end()){

                        que.push({temp, steps+1});

                        word_set.erase(temp);
                    }
                }
            }
        }


        return 0;

    }
};