class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(s.empty() || s.size()<k){
            return 0;
        }
        int maxlength = -1;
        unordered_map<char, int> freq;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }

        for(int i=0;i<s.size();i++){

            if(freq[s[i]]<k){

                int left_substring = longestSubstring(s.substr(0,i),k);
                
                int right_substring = longestSubstring(s.substr(i+1),k);

                return max(left_substring, right_substring);
            }
        }

        return s.size();
    }
};