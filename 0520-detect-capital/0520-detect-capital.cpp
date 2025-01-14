class Solution {
public:
    bool detectCapitalUse(string word) {

        int n  = word.size();
        int count_capitals=0;
        
        for(int i=0;i<n;i++){
         if (isupper(word[i])){
                count_capitals++;
            }
        }

        if(count_capitals==0 ){   // means ik bhi capital nhi hai .. saare lowercase hai.. 
            return true;
        }

        if(count_capitals == n) {  // measn saare letters capital hai 
            return true;
        }

        if(count_capitals==1 && isupper(word[0])){  // mtlb sirf ik hee capital hai .. vo bhi first cahracter
            return true;
        }

        return false;
    }
};