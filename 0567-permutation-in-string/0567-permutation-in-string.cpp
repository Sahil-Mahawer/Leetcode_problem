class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // sort(s1.begin(), s1.end());

        int m = s2.size();
        int n = s1.size();

        // for(int i=0;i<=m-n;i++)
        // {
        //     string substring = s2.substr(i,n);   // n is the length .. second argument in the s.substr() is the length means how many character we have to take from the starting index

        //     sort(substring.begin(), substring.end());

        //     if(s1 == substring){
        //         return true;
        //     }
        // }

        // return false;


        vector<int> s1_vec(26,0);

        for(int i=0;i<n;i++)
        {
            char ch = s1[i];
            s1_vec[ch - 'a']++;
        }


        int i = 0, j = 0;
        vector<int> window_vec(26,0);

        while(j < m)
        {
            char right = s2[j];
            window_vec[right - 'a']++;


            while( j-i+1 > s1.size()){

                window_vec[s2[i] - 'a' ]--;

                i++;

            }

            if(window_vec == s1_vec){
                return true;
            }

            j++;
        }

        return false;

    }
};