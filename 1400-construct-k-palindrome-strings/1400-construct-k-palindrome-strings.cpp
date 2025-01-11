class Solution {
public:
    bool canConstruct(string s, int k) {
        
        // no. of odd frequency vaale charcter <=k hone chahiya tbhi palindrome bnega..

        // even no. frequency character toh koii dikkt krenge nhi ..  hmesha bnega 

        // if(s.size()==k)  .... tbh bhi palindrome bnega ... each character also treats as palindrome.

        if(s.size()<k){
            return false;
        }

        if(s.size()==k){
            return true;
        }

        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++){

            freq[s[i]]++;
        }  

        int odd_freq_count=0;
        for(int i=0;i<s.size();i++){

            if(freq[s[i]]%2!=0){
                odd_freq_count++;
            }
        }


        if(odd_freq_count<=k){
            return true;
        }

        else
        {
            return false;
        }




    }
};