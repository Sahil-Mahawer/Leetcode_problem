class Solution {
public:

int solve(int start , int end , string &word , int k ){

    int result=0;

    for(int unique_char = 1 ; unique_char <=26 && unique_char*k <= end-start+1 ;  unique_char++){

        unordered_map<char,int> count;
        int goodboy=0;

        // Now start Sliding Window
           int i = start;
           int windowlength = unique_char*k;

           for(int j=start; j<=end; j++){

             char ch = word[j];

             count[ch]++;

             if(count[ch] == k){
                goodboy+=1;
             }
             else if(count[ch] == k+1){

                goodboy-=1;
             }

            if(j-i+1 > windowlength){   // time to slide the window ... shrink from left side

                // ith index character hatne vaala hai 
                if(count[word[i]] == k){
                    goodboy-=1;
                }
                else if(count[word[i]] == k+1){  // k+1-1 = k 
                    goodboy+=1;
                }
                count[word[i]]--;
                i++;
            }

            if(goodboy == unique_char)
            {
                result+=1;
            }

           }


    }

    return result;

}



    int countCompleteSubstrings(string word, int k) {
        
        int n = word.length();
        int last = 0, result=0;

        for(int i=1;i<=n;i++){

            if( i==n||abs(word[i]-word[i-1])>2){   // dividing condition  :- bORDERS DRAW krenge   
            // i==n this for last segment .. only because of this condition we enter into the loop 
                result +=solve(last , i-1, word , k);           // last ka matlab starting point 
                last = i;
            }
        }

        return result;
    }
};