class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n  = s.size();
       
        for(int len=1;len<=n/2;len++){
            
            if(n%len==0){

                string sub = s.substr(0,len);
                string check="";

                for(int i=0;i<n/len;i++){
                    check += sub;
                }

                if(check == s){
                    return true;
                }
            }
        }

        return false;

    //      vector<int> lps(s.size(),0);
        
    //     int pre= 0;
    //     int suff= 1;
        
    //     while(suff < s.size()){
            
    //         if(s[pre] == s[suff]){
                
    //             lps[suff] = pre+1;
    //             pre++;
    //             suff++;
                
               
                
    //         }
            
    //         else
    //         {
    //             if(pre==0){
    //                 lps[suff]=0;
    //                 suff++;
    //             }
                
    //             else
    //             {
    //                 pre = lps[pre-1];
    //             }
    //         }
    //     }
        
    //    if(lps[lps.size()-1]==0){
    //     return false;
    //    }
       
    //    return true;
    }
};