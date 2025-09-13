class Solution {
public:
    int maxFreqSum(string s) {
        
        unordered_map<char,int> vowel_mp;
        unordered_map<char,int> conso_mp;

        for(int i=0; i<s.size(); i++){

            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){

                vowel_mp[s[i]]++;
            }

            else{

                conso_mp[s[i]]++;
            }
        }

        int vow_max = 0;

        for(auto it = vowel_mp.begin(); it!= vowel_mp.end(); it++){

            vow_max = max(vow_max, it->second);
        }



        int conso_max = 0;

        for(auto it = conso_mp.begin(); it!= conso_mp.end(); it++){

            conso_max = max(conso_max, it->second);
        }

        return conso_max + vow_max;
    }
};