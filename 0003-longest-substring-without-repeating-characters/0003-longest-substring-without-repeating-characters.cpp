class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();

        unordered_set<char> st;

        int i = 0, j = 0, max_length = 0;

        while(j < n){

            while(st.find(s[j]) != st.end()){

                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            max_length = max(max_length, j-i+1);
            j++;
        }

        return max_length;
    }
};