class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count = 0;              // Count unmatched closing parentheses ')'
        stack<char> st;            // Stack to keep track of unmatched opening parentheses '('

        for(int i = 0; i < s.size(); i++) {   // Loop through the entire string
            if(s[i] == '(') {     // If current character is an opening bracket
                st.push(s[i]);    // Push it onto the stack
            }
            else {                // If current character is a closing bracket ')'
                if(st.empty()) {  // If there is no matching opening bracket
                    count++;      // Increment count (we'll need to add an opening bracket)
                }
                else {
                    st.pop();     // Pop the matching opening bracket from the stack
                }
            }
        }

        // Final result is:
        // count -> unmatched closing brackets
        // st.size() -> unmatched opening brackets
        return count + st.size();  // Total brackets to add to make string valid
    }
};
