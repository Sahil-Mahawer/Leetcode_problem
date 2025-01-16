class Solution {
public:
    string longestNiceSubstring(string s) {
        
        if(s.size()<2){
            return "";
        }

        unordered_set<char> check(s.begin(), s.end());

        for(int i=0;i<s.size();i++){

            char ch = s[i];

            if(check.count(tolower(ch))==0  ||  check.count(toupper(ch))==0){



                string left_substring  =  longestNiceSubstring(s.substr(0,i));

                string right_substring =  longestNiceSubstring(s.substr(i+1));

                if(left_substring.size()>= right_substring.size()){
                    return left_substring;
                }
                else{
                    return right_substring;
                }

            }

        }

        return s;
    }
};