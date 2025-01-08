class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxlength= 0;

        int n = s.size();

        for(int i=0;i<n;i++){

            unordered_set<char> unique;

            for(int j=i;j<n;j++){

                if(unique.find(s[j])!=unique.end()){
                    break;
                }

                unique.insert(s[j]);
                maxlength = max(maxlength, j-i+1);
            }
        }
        return maxlength;
    }
};