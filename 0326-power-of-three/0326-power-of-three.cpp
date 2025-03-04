class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0 || n<0){
            return false;
        }

        if(n==1){
            return true;
        }

       

        for(int i=1;i<=31;i++){

            if(pow(3,i) == n){
                return true;
            }

            if(pow(3,i) > n){
                break;
            }
        }

        return false;
    }
};