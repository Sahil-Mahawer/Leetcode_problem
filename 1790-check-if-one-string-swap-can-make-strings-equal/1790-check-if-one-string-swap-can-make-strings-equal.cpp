class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        
        if(s1==s2){
            return true;
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                swap(s1[i],s1[j]);

                if(s1==s2){
                    return true;
                }

                swap(s1[i],s1[j]);
            }
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                swap(s2[i],s2[j]);

                if(s1==s2){
                    return true;
                }

                swap(s2[i],s2[j]);
            }
        }
        return false;
    }
};

