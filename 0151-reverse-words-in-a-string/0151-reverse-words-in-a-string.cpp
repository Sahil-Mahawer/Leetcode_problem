class Solution {
public:
    string reverseWords(string s) {
       
     // 1. reverse whole string 
     reverse(s.begin(), s.end());

     int n = s.size();

     int l=0;
     int r = 0;
     // l and r hai jo reverse krenge 
     int i=0;
     
     while(i<n){

        while(i<n && s[i]!=' '){  // i ko agrr character dikha toh vo r ko dega and then i++, r++
            s[r] = s[i];
            i++;
            r++;
        }

        if(l<r){
            reverse(s.begin()+l , s.begin()+r);
            s[r]  = ' ';
            r++;
            l = r;
        }
        i++;

     }

     s = s.substr(0 , r-1);

     return s;


    }
};