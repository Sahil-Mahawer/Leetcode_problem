class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count = 0;
        stack<char> st;

        for(int i=0;i<s.size();i++){

            if(s[i] == '('){  // opening bracket
                st.push(s[i]);
            }
            else{  // closed bracket

                if(st.empty()){
                    count++;   // means you only have closed bracket no opening bracket is present 
                }
                else{
                    st.pop();
                }
            }
        }

        return count + st.size(); // st.size() is for like if only opening bracket is present   
    }
};