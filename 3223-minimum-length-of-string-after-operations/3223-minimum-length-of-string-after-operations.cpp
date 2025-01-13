class Solution {
public:
    int minimumLength(string s) {

        if(s.size()<=2){
            return s.size();
        }

        int size =s.size();

        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }

       
       for(auto it = freq.begin(); it!=freq.end();it++){

        int check = it->second;

        if(check%2==0 && check>2){
            size = size - (check-2);
        } 
        else if(check%2!=0 && check >2){
            size  = size - (check-1);
        }
       }
        return size;
    }
};