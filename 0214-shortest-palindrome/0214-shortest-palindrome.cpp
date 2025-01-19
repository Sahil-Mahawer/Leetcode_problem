class Solution {
public:
    string shortestPalindrome(string s) {  // in palindrome forward and backward character should be same

    //  ---->>> Brute Force --->>>
        
        // int n = s.size();
        // int first = 0;
        // int second =  n-1;
        // int count = 0;

        // while(first<=second){

        //     if(s[first]==s[second]){
        //         first++;
        //         second--;
        //     }

        //     else
        //     {
        //      count++;
        //      first = 0;
        //      second = n-1-count;
        //     }
        // }
        // string rev = s;

        // reverse(rev.begin(), rev.end());

        // string result = rev.substr(0,count)+s;

        // return result; 


        // ------>>> Optimal Approach ---->>>> 

        int pre = 0;
        int suff = 1;
        int n = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string check;
        check = s+'$'+rev;
        int size = check.size();

        vector<int> lps(size,0);

        while(suff < size){

            if(check[pre] == check[suff]){
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
                else{
                    pre = lps[pre-1];
                }
            }
        }

        int count = n - lps[lps.size()-1];

        string result = rev.substr(0,count)+s;

        return result; 
    }
};