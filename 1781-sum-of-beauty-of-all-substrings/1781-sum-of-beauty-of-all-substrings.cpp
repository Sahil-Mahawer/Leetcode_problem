class Solution {
public:
    int beautySum(string s) {
        
       int n = s.size();

       int result = 0;

       for(int i=0;i<n;i++){
       
       unordered_map<char, int> freq;
       unordered_set<char> count;
       int max_count = INT_MIN;
       int min_count = INT_MAX;

       for(int j=i;j<n;j++){
         
        count.insert(s[j]);
        freq[s[j]]++;

        if(count.size()>1){
            for(auto it = freq.begin(); it!=freq.end();it++){
            max_count = max(max_count, it->second);
            min_count = min(min_count , it->second);

           
            }
             result += max_count - min_count;
        }

         
       }

       }
       return result;
    }
};