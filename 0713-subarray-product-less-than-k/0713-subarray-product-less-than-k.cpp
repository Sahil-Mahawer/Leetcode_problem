class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {

         //----->>>>  Brute Force Approach --->>>>

        // int count=0;
        // if (k <= 1) return 0;

        // for(int i=0;i<arr.size();i++){
            
        //     int product = 1;
            

        //     for(int j=i;j<arr.size();j++){

        //         product = product*arr[j];

        //         if(product<k){
        //          count++;    // Count the current subarray as valid
        //         }
        //         else{
        //             break;  // No point in continuing as the product will only grow larger
        //         }
        //     }
        // }

        // return count;


        // ----->>> Optimal Aprroach ------>>>



        // int n = arr.size();

        // int start=0;
        // int end = 0;
        // int product=1;
        // int count=0;

        // while(end<n){
        //     product = product*arr[end];

        //     while(product>=k && start<=end){
        //         product = product/arr[start]; // shrinking phase
        //         start++;
        //     }
        //     count = count+(end-start+1);
        //     end++;
        // }
        // return count;



        int product = 1;

        int start = 0;
        int end = 0;

        int n = arr.size();

        int count = 0;

        while(end < n){

            product = product * arr[end];

            while(product >= k  && start <= end){

                product = product / arr[start];
                start++;
            }
            count += end-start+1;
            end++;
        }
        
        return count;

    }
};