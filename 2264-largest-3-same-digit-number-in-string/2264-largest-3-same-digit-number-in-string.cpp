class Solution {
public:
    string largestGoodInteger(string s) {
        
        int n = s.size();
        unordered_map<char, int> char_freq;
        string result="";
        char value;
        int check = -1;
        int digit = 0;

        for(int i=0;i<n;i++){
            char_freq[s[i]]++;
        }

        for(auto it=char_freq.begin(); it!=char_freq.end();it++){
            int freq = it->second;

            if(freq == 3){
                value = it->first;
                digit = value - '0';
                if(digit>check){
                    check = digit;
                }
            }
        }

        if(check == -1){
            return "";
        }
        result = to_string(check);
        result += result+result;

        return result;
    }
};