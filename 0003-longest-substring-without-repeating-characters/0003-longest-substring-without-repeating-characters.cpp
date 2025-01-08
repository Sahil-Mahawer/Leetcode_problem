class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
    //    --->>>> Brute Force Approach ----->>>>

    //     int maxlength= 0;

        int n = s.size();

    //     for(int i=0;i<n;i++){

    //         unordered_set<char> unique;

    //         for(int j=i;j<n;j++){

    //             if(unique.find(s[j])!=unique.end()){
    //                 break;
    //             }

    //             unique.insert(s[j]);
    //             maxlength = max(maxlength, j-i+1);
    //         }
    //     }
    //     return maxlength;


    // ----->>>>> Optimal Approach ------>>>>

    int start = 0, end = 0;
    int maxlength=0;

    unordered_set<char> unique;

    while(end<n){

        while(unique.find(s[end])!=unique.end()){

            unique.erase(s[start]);
            start++;
        }
        unique.insert(s[end]);
        maxlength = max(maxlength, end-start+1);
        end++;
    }

    return maxlength;
     }
};