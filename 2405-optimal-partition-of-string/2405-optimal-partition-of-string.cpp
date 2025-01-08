class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char> unique;
        int count=0;

        for(int i=0;i<s.size();i++){

            if(unique.find(s[i])!=unique.end()){
                count++;
                unique.clear();
            }
            unique.insert(s[i]);
            
        }
       count++;
       return count;
    }
};