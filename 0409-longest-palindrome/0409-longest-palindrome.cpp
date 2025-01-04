class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++){

            freq[s[i]]++;
        }

        int count=0;
        bool odd=0;

        for(auto i=freq.begin(); i!=freq.end();i++){

            int freq_count = i->second;

            if(freq_count%2==0){
                count += freq_count;
            }

            else
            {
                count += (freq_count-1);
                odd=1;
            }
        }

        return count+odd;
    }
};