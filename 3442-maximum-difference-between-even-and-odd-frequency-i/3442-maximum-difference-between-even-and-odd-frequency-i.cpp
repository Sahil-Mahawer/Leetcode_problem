class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char, int> mp;

        for(int i =0; i<s.size(); i++){

            mp[s[i]]++;
        }

        int odd = INT_MIN;
        int even = INT_MAX;

        for(auto it = mp.begin(); it!= mp.end(); it++){
            int freq = it->second;

            if(freq % 2 != 0){
            odd = max(odd, freq);
            }
            else{
            even = min(even, freq);
            }
        }

        return odd - even;
    }
};