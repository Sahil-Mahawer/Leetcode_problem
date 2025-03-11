class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int start = 0, end = 0 , n = s.size();

        int count_a = 0 , count_b = 0, count_c = 0;
        
         




        int count_subaarays = 0;

        while(end < n){

            if(s[end] == 'a'){
                count_a++;
            }
            else if(s[end] == 'b'){
                count_b++;
            }
            else if(s[end] == 'c'){
                count_c++;
            }


            while(count_a>=1 && count_b>=1 && count_c>=1){

                count_subaarays += (n-end);


             if(s[start] == 'a'){
                count_a--;
            }
            else if(s[start] == 'b'){
                count_b--;
            }
            else if(s[start] == 'c'){
                count_c--;
            }

            start++;


            }
            end++;
        }

        return  count_subaarays;
    }
};