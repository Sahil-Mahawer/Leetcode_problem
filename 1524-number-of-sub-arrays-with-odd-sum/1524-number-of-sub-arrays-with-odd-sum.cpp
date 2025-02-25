class Solution {
public:
int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        
        // int count = 0;

        // for(int i=0;i<arr.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<arr.size();j++){

        //         sum+=arr[j];
        //         if(sum%2==1){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        int n = arr.size();

        vector<int> prefix(n,0);

        prefix[0] = arr[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+arr[i];
        }

        int odd_count = 0;
        int even_count = 1;
        int count =0;

        for(int i=0;i<n;i++){

            if(prefix[i]%2!=0){
                count = (count+even_count)%m;  // agrr prefix sum odd aagya toh chek krro usee phle kitne even sum hai 
                // becoz odd + even = odd 

                odd_count++;
            }
            else  // even + odd = odd
            {
                 count = (count + odd_count)%m;

                 even_count++;
            }
        }
        return count;
    }
};