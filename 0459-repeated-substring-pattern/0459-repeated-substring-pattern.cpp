class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        // int n  = s.size();
        // string sub ="";
        // int size;

        // for(int i=0;i<n-1;i++){
        //     sub += s[i];
        //     string check="";
        //     if(n%2==0){

        //         size = n / sub.size();

        //         while(size){
        //             check += s[i];
        //             size--;
        //         }

        //         if(check==s){
        //             return true;
        //         }
        //     }

        //     else
        //     {
        //        size = n / sub.size();
        //        while(size){
        //             check += s[i];
        //             size--;
        //         }

        //         if(check==s){
        //             return true;
        //         }
        //     }

        // }
        // return false;

         vector<int> lps(s.size(),0);
        
        int pre= 0;
        int suff= 1;
        
        while(suff < s.size()){
            
            if(s[pre] == s[suff]){
                
                lps[suff] = pre+1;
                pre++;
                suff++;
                
               
                
            }
            
            else
            {
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                
                else
                {
                    pre = lps[pre-1];
                }
            }
        }
        
       if(lps[lps.size()-1]==0){
        return false;
       }
       
       return true;
    }
};