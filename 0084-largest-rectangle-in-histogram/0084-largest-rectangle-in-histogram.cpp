class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;

        vector<int> next_smallest_right(n);
        vector<int> next_smallest_left(n);

        // next smallest right
        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()] > heights[i]){

                next_smallest_right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()){

            next_smallest_right[st.top()] = n;   // jinka koi left smallest milla nhi unko 'n' dediya 
            st.pop();
        }


        // next smallest left
        for(int i = n-1; i>=0; i--){

            while(!st.empty() && heights[st.top()] > heights[i] ){
                
                next_smallest_left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            next_smallest_left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;

        for(int i=0;i<n;i++){

            ans = max(ans, heights[i]*(next_smallest_right[i] - next_smallest_left[i] - 1));
        }

        return ans;

    }
};