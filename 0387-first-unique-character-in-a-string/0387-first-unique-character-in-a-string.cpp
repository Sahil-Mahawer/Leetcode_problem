class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> mp(256,0);

        for(int i=0;i<s.size();i++){

            mp[s[i]]++;
        }

       
       for(int i = 0; i<s.size(); i++){

        if(mp[s[i]] == 1){
            return i;
        }

       }
        
        return -1;
    }
};