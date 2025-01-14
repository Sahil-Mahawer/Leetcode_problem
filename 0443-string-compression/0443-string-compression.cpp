class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int index = 0;
        int i =0;

        while(i<n){
        char current_char = chars[i];
        int count = 0;

        while(i<n && chars[i]==current_char){
            count++;
            i++;
        }

        chars[index] = current_char;
        index++;

        if(count>1){

            string count_str = to_string(count);

            for(int j=0;j<count_str.size();j++){
                chars[index] = count_str[j];
                index++;
            }
        }

        }

        return index;
    }
};