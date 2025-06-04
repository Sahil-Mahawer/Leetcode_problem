class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n = word.size();

        if(n==1){
            return word;
        }

        int longest_possible_string = n - (numFriends-1); // total maanle 3 friends hai tere pass and word ka size 5 hai .. toh lexographically largest ke liya ham  Lexicographically largest character se shuru krenge .. toh hmare pass jaise 3 friends tha toh 1 friend ko maximum de sakte hai  and baaki 2 ko minimum means sirf 1 character aise hmm maximum nikal skte hai   ........ 

        string result = "";

        for(int i = 0; i<n; i++){

           int  can_take = min(longest_possible_string, n-i);

            result = max(result, word.substr(i, can_take));
        }

        return result;
        
    }
};