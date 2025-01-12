class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
         int n = s.size();

         if(goal.size()!= s.size()){
            return false;
         }

        unordered_map<char,int> freq;

         if(s==goal){
         for(int i=0;i<n;i++){
            freq[s[i]]++;

            if(freq[s[i]]>1){
                return true;
            }
         }

         return false;
         }


        vector<int> diffindices;

        for(int i=0;i<n;i++){

            if(s[i]!=goal[i]){
                diffindices.push_back(i);
            }
        }

        if(diffindices.size()==2){
        
        int i = diffindices[0];
        int j = diffindices[1];

        swap(s[i],s[j]);

        if(s==goal)
        return true;;
    }

    return false;
    }
};