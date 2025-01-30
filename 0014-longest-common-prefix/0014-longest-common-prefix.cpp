class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        int n = strs.size();

        for(int i=1;i<n;i++){

            while(strs[i].find(prefix)!=0){  
                prefix = prefix.substr(0, prefix.size()-1);
                if(prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};