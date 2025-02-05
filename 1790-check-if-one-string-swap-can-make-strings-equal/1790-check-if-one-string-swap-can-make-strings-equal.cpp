class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        
        if(s1==s2){
            return true;
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                swap(s1[i],s1[j]);

                if(s1==s2){
                    return true;
                }

                swap(s1[i],s1[j]);
            }
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                swap(s2[i],s2[j]);

                if(s1==s2){
                    return true;
                }

                swap(s2[i],s2[j]);
            }
        }
        return false;




        // optimal Approach ---->>>>

        //  if (s1 == s2) {
        //     return true;
        // }

        // vector<int> diffIndices;

        // // Collect indices where characters differ

        // for (int i = 0; i < s1.size(); i++) {
        //     if (s1[i] != s2[i]) {
        //         diffIndices.push_back(i);
        //     }
        // }

        // // If more than 2 characters differ, return false

        // if (diffIndices.size() != 2) {
        //     return false;
        // }

        // // Check if swapping makes strings equal
        
        // int i = diffIndices[0], j = diffIndices[1];
        // swap(s1[i], s1[j]);
        // return s1 == s2;
    }
};



