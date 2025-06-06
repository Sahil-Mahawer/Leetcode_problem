class Solution {
public:
    string robotWithString(string s) {
        
        int n = s.size();

        vector<char> minChar_To_right(n);

        minChar_To_right[n-1] = s[n-1];

        for(int i = n-2; i>=0; i--){

            minChar_To_right[i] = min(s[i], minChar_To_right[i+1]);
        }

        string paper = "";
        string t = "";

        int i = 0;

        while(i < n)
        {

            t.push_back(s[i]);

            char min_char =(i+1 < n)? minChar_To_right[i+1] : s[i] ;


            while(!t.empty() &&  t.back() <= min_char){

                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        while(!t.empty()){

            paper += t.back();
            t.pop_back();
        }

        return paper;

    }
};