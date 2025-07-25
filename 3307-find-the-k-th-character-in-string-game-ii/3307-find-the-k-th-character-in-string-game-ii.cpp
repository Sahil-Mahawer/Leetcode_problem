class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        if(k == 1){
            return 'a';
        }

        int n = operations.size();
        long long len = 1;
        long long newk  = -1;
        int operation_Type  = -1;

        for(int i=0; i<n; i++){

            len *=2;

            if(len >= k){
                operation_Type = operations[i];
                newk = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newk, operations);

        if(operation_Type == 0){
            return ch;
        }
        

        return ch == 'z' ? 'a' : ch+1;

        
         
    }
};