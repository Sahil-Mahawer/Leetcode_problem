class Solution {
public:
    int longestBalanced(string s) {

       int ans = 0;

       for(int i=0; i<s.size(); i++){

            unordered_map<char, int> freq; 

        for(int j = i; j<s.size(); j++){

            freq[s[j]]++;

            int min_freq = INT_MAX;
            int max_freq = INT_MIN;

            for(auto it=freq.begin(); it!=freq.end(); it++){

                min_freq = min(min_freq, it->second);
                max_freq = max(max_freq, it->second);
            }

            if(min_freq == max_freq){

                ans = max(ans, j-i+1);
            }
        }


       }

       return ans; 

    }
};