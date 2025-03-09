class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        
        // Append the (k-1) elements at the back of the  array to handle the circular nature 
        vector<int> extended(colors.begin(), colors.end());
        extended.insert(extended.end(), colors.begin(), colors.begin() + (k - 1));

        int count = 0;
        int i = 0, j = 1; // Sliding window pointers

        int N = n+(k-1);  // new Vector size

        while(j<N){


            if(extended[j] == extended[j-1]){
                i=j;
                j++;
                continue;
            }

            if(j-i+1 == k){
                count++;
                i++;
            }
            j++;
        }
        
        return count;
    }
};
