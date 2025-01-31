class Solution {
public:
    int minSteps(string s, string t) {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int count = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                count++;
            }
        }
        return count;
    }
};