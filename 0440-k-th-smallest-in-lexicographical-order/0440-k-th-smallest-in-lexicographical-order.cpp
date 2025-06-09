class Solution {
public:

   long long Count(long long curr, long long next, int n) {
    long long count_num = 0;

    while (curr <= n) {
        count_num += min((long long)n + 1, next) - curr;
        curr *= 10;
        next *= 10;
    }

    return count_num;
}


    int findKthNumber(int n, int k) {
        
        
        int curr = 1;
        k -=1;


        while(k > 0){

            int count = Count(curr, curr+1, n);

            if(count <= k){
                curr++;
                k -= count;
            }
            else{

                curr *=10;
                k -= 1; 
            }
        }

        return curr;
    }
};