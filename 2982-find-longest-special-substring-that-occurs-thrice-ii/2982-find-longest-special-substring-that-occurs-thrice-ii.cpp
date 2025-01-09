class Solution {
public:
    int maximumLength(string s) {

        int n = s.size();
        
        vector<vector<int>> matrix(26, vector<int>(n+1,0));     // row represent alphabet eg:- a=0, b=1, c=2 ...... mens 0th row "a" ki hai , 1st rwo "b" ki hai   ..... 
                                                                // col represent length of sub-string

        char prev_char = s[0];
        int length = 0;

        for(int i=0;i<n;i++){

           char curr_char = s[i];

           if(curr_char == prev_char){
            length++;
            matrix[curr_char-'a'][length]++;
           }
           else{
            length = 1;
            matrix[curr_char-'a'][length]++;
            prev_char = curr_char;
           }
        }
        int result = 0;
        for(int i=0;i<26;i++){

            int cum_sum = 0;

            for(int j=n;j>=1;j--){
                cum_sum += matrix[i][j];  // here cummulative sum represent count of substring ;

                if(cum_sum>=3){
                result  = max(result, j);
                }
            }
        }

        if(result==0) return -1;
        else 
        return result; 
    }
};