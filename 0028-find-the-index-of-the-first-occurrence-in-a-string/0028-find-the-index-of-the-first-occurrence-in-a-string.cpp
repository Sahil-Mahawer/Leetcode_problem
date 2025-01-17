class Solution {
public:

void lpsfind(vector<int> &lps, string pat){
      
      
       int prefix = 0;
        int suffix = 1;
        
        while(suffix <  pat.size()){
            
            if(pat[prefix] == pat[suffix] ){
                
                lps[suffix] = prefix+1;
                prefix++;
                suffix++;
            }
            
            else
            {
                if(prefix == 0){
                    lps[suffix]=0;
                    suffix++;
                }
                
                else
                {
                   prefix = lps[prefix-1];
                }
            }
        }
  }

    int strStr(string haystack, string needle) {
        
         vector<int> lps(needle.size(),0);
        lpsfind(lps, needle);
        
        int first =0;
        int second= 0;
        
        while(second<needle.size() && first< haystack.size()){
            
            if(haystack[first] == needle[second]){
                first++;
                second++;
            }
            
            else
            {
                if(second==0){
                    first++;
                }
                else{
                second = lps[second-1];
                }
            }
        }

        if(second == needle.size()){
            return first-second;
        }
        else
        {
            return -1;
        }

    }
};