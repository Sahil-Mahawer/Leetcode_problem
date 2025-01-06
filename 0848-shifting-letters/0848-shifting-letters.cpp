class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n = shifts.size();
        int prefixsum=0;

        for(int i=n-1;i>=0;i--){
            prefixsum = (prefixsum+shifts[i])%26;  // calculating prefixsum in reverse order .... and mod 26 is done to do wrap around 
            s[i] = ((s[i] - 'a')+prefixsum)%26 + 'a';
        }

        return s;
    }
};