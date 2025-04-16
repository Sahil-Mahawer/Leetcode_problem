class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();

        vector<int> ans;

        stack<int> st;

        for(int i=0;i<n;i++){

           while(!st.empty() && st.top() > 0 && asteroids[i] < 0 ){

                int element = st.top();

                if(element == abs(asteroids[i])){
                    st.pop();
                    goto skip_push;
                }
                else if( element != abs(asteroids[i])){

                    if(element < abs(asteroids[i])){
                        st.pop();
                    }
                    else{
                        goto skip_push;
                    }
                }
           }

           st.push(asteroids[i]);

           skip_push: ;
        

        }

        while(!st.empty()){

            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};