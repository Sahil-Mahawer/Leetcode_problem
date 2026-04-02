class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> s1_map;
        unordered_map<char,int> s2_map;

        for(int i=0; i<s1.size(); i++){

            s1_map[s1[i]]++;
        }

        int i=0, j=0; 

        while(j < s2.size()){

            s2_map[s2[j]]++;

            if(j-i+1 > s1.size()){

                s2_map[s2[i]]--;

                if(s2_map[s2[i]] == 0){
                    s2_map.erase(s2[i]);
                }
                i++;
            }

            if(s1_map == s2_map){
                return true;
            }
            j++;
        }

        return false;
    }
};