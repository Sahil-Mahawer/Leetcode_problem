class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){

            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

           else {

            if(st.empty()){
                return false;
            }

            else if (s[i] == ')'){

                if(st.top() != '('){
                    return false;
                }
                else{
                    st.pop();
                }
            }

            else if(s[i] == '}'){

                if(st.top() != '{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }

            else{
                if(st.top() != '['){
                    return false;
                }
                else{
                    st.pop();
                }
            }

           }
                   
        }

        return st.empty();
    }
};