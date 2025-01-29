class Solution {
public:
    bool areNumbersAscending(string s) {

        int n = s.size();

        stringstream ss(s);
        int prev = -1;

        string word;

        while(ss >> word){

            if(isdigit(word[0])){
                int num = stoi(word);

                if(num<=prev){
                    return false;
                }
                prev = num;
            }
        }
        
        return true;
       
    }
};