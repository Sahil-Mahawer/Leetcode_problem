class Solution {
public:
    int longestPalindrome(string s) {
        
        // --->>> using hashmap --->>>> 

        // unordered_map<char,int> freq;

        // for(int i=0;i<s.size();i++){

        //     freq[s[i]]++;
        // }

        // int count=0;
        // bool odd=0;

        // for(auto i=freq.begin(); i!=freq.end();i++){

        //     int freq_count = i->second;

        //     if(freq_count%2==0){
        //         count += freq_count;
        //     }

        //     else
        //     {
        //         count += (freq_count-1);
        //         odd=1;
        //     }
        // }

        // return count+odd;

        
        // ------>>> using vector ----->>>>>

        vector<int> lower(26,0) , upper(26,0);

        for(int i=0;i<s.size();i++){

            if(s[i]>='a'){  // lowercase character
            lower[s[i]-'a']++;
            }

            else{  // uppercase alphabet
              upper[s[i]-'A'];
            }
        }
        int count = 0;
        bool odd=0;
        for(int i=0;i<26;i++){

            if(lower[i]%2==0){
                count += lower[i]; 
            }

            else{
                count += (lower[i]-1);
                odd=1;
            }


            if(upper[i]%2==0){
                count += upper[i]; 
            }

            else{
                count += (upper[i]-1);
                odd=1;
            }

        }

        return count+odd;
    }
};