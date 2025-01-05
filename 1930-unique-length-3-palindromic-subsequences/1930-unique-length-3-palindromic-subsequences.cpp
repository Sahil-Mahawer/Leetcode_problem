class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char,int> mpp;
        int count = 0, n = s.size();

        

        for(int i=0;i<n;i++){

            if(mpp.find(s[i])!=mpp.end()){
                int elements = (i-mpp[s[i]])-1;
                count = count+elements;
            }

            else
            {
                mpp[s[i]]=i;
            }
        }

        return count;
    }
};