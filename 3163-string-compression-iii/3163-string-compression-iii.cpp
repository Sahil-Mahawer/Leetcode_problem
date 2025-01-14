class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";
        int n = word.size();
        int i=0;

        while(i<n){
            char curr_char = word[i];
            int count=0;

            while(i<n && curr_char == word[i] && count<9){
                count++;
                i++;
            }

            comp += to_string(count)+ curr_char;
        } 
        return comp;
    }
};