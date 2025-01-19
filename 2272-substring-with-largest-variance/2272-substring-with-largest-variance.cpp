class Solution {
public:
    int largestVariance(string s) {
        
        vector<int> count(26,0);

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            count[ch-'a']=1;
        }

        int result = 0;

        for(char first = 'a'; first<='z';first++){

            for(char second = 'a'; second<='z';second++){

                if(count[first-'a']==0 || count[second-'a']==0){
                    continue;
                }

                int first_count = 0;
                int second_count = 0;

                bool past_second = false;

                for(int i=0;i<s.size();i++){
                    char ch = s[i];

                    if(ch == first){
                        first_count++;
                    }
                    if(ch == second){
                        second_count++;
                    }

                    if(second_count>0){
                     result = max(result , first_count - second_count);
                    }
                    else  // means second_count 0 hai , toh check krlo ki phle second character aaya tha .. ki humne pehle uss character ko dekha hai ki nhi  
                    {
                        if(past_second == true){
                            result  = max(result, first_count-1);
                        }
                    }

                    if(first_count < second_count){
                        first_count = 0;
                        second_count = 0;
                        past_second = true;
                    }
                }
            }
        }

        return result;
    }
};