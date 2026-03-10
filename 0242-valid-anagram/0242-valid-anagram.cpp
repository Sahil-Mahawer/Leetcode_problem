class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> mp1;

        for(int i=0; i<s.size(); i++){

            mp1[s[i]]++;
        }

        unordered_map<char,int> mp2;

        for(int i=0; i<t.size(); i++){

            mp2[t[i]]++;
        }

        if(mp1 == mp2){
            return true;
        }

        return false;
    }
};