class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> st;

        vector<int>NSR(n,n);
        vector<int> NSL(n,-1);

        int m = 1e9+7;

        // Next Smaller right
        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                NSR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // Already intitialize NSL with n , so no need to give n to remaining values 

        // while(!st.empty()){  
        //     NSR[st.top()] = n;
        //     st.pop();
        // }


        // Next Smaller Left
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()] > arr[i] ){

                NSL[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Already intitialize NSL with -1 , so no need to give -1 to remaining values 

        // while(!st.empty()){
        //     NSL[st.top()] = -1;
        //     st.pop();
        // }

        long long sum = 0;

        for(int i=0;i<n;i++){

            long long ls = i - NSL[i];  // minimum element ke left mai kitne element hai
            long long rs = NSR[i] - i;  // minimum element ke right mai kitne element hai

            long long total_ways = ls*rs;  // total kitne subarrays hai jisme arr[i] minimum hai

            long long total_sum = arr[i] * total_ways; 

            sum = (sum+total_sum)%m;
        }

        return sum;
    }
};