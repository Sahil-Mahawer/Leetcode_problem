class Solution {
public:
    bool isValid(string word) {
        
        if(word.size() < 3){
            return false;
        }

        bool hasvowel = false;
        bool has_consonant = false;

        for(int i = 0; i<word.size(); i++){

            char ch = word[i];

            if(isalpha(ch)){

                ch = tolower(ch);

                if(ch == 'a' ||ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){

                    hasvowel = true;

                }
                else{
                    has_consonant = true;
                }
            }
            else if(!isdigit(ch)){
                return false;
            }
        } 

        return hasvowel && has_consonant;
    }
};