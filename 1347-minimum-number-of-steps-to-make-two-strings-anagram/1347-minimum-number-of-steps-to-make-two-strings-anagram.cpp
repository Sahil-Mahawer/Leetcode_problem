class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mpp;
        int count=0;

        for(int i=0;i<t.size();i++){
            mpp[s[i]]++;
        }

        for(int i=0;i<t.size();i++){

            char ch = t[i];

            if(mpp.find(ch)==mpp.end()){
                count++;
            }
            else{
                mpp[ch]--;
                if(mpp[ch]==0){
                    mpp.erase(ch);
                }
            }
        }

        return count;
    }
};