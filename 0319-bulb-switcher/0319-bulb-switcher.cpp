class Solution {
public:
    int bulbSwitch(int n) {
        
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }

        return sqrt(n);
    }
};