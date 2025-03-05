class Solution {
public:
    int numberOfCuts(int n) {
        
        if(n==1){
            return 0;
        }

        if(n%2==0){ // even parts
            return n/2;
        }
        

        return n;

    }
};