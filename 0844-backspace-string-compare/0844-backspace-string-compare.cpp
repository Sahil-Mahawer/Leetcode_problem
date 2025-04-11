class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st;

        // Process string s
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '#') {
                st.push(s[i]);
            } else if(!st.empty()) {
                st.pop();
            }
        }

        vector<char> ans1;

        // Transfer stack contents to vector for s
        while(!st.empty()) {
            ans1.push_back(st.top());
            st.pop();
        }

        stack<char> st2;

        // Process string t
        for(int i = 0; i < t.size(); i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            } else if(!st2.empty()) {
                st2.pop();
            }
        }

        vector<char> ans2;

        // Transfer stack contents to vector for t
        while(!st2.empty()) {
            ans2.push_back(st2.top());
            st2.pop();
        }

        // Compare the resulting vectors
        return ans1 == ans2;
    }
};
