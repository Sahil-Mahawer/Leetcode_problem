class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> result;

       int i = 0;
       int n = s.size();

       while(i < n){

        int j = (i+k-1 >=n) ? n-1 : (i+k-1);

        string temp = s.substr(i, j-i+1);

        if(j-i+1 < k){

            int rem = k - (j-i+1);

            temp+= string(rem, fill);
        }

        result.push_back(temp);

        i = i+k;

       }

        return result;
    }
};