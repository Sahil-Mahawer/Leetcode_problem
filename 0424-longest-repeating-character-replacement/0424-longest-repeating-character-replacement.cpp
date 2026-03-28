class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0, r = 0, n = s.size(), max_len = 0, max_freq = 0;
        unordered_map<char,int> mp;

        while(r < n){

            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);


            while((r-l+1) - max_freq > k){

                mp[s[l]]--;
                l++;
            } 

            if((r-l+1) - max_freq <= k){
                max_len = max(max_len, (r-l+1));
            }

            r++;
        }
            return max_len;
    }
};