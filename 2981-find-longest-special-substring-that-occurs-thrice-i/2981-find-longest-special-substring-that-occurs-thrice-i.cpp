class Solution {
public:
    int maximumLength(string s) {
        
        int n = s.size();
        unordered_map<string, int> mpp;  // current substring and uska count;
        
            int maxlength = -1;

        for(int i=0;i<n;i++){

            string curr;

            for(int j=i;j<n;j++){

                if(curr.empty() || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    mpp[curr]++;
                }
                else
                {
                    break;
                }
            }

            for(auto it = mpp.begin(); it!=mpp.end();it++){
                int count = it->second;
                string substring = it->first;

                if(count>=3){
                    maxlength = max(maxlength, (int)substring.length());
                }
            }
        }

        return maxlength;
    }
};