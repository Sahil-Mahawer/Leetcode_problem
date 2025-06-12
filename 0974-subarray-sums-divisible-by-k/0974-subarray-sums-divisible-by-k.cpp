class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
    //  ------>>>> Brute Force Approach ----->>>

        // int n = arr.size();
        // int count=0;

        // for(int i=0;i<n;i++){
        //     int prefixSum = 0; 

        //     for(int j=i;j<n;j++){
        //         prefixSum+=arr[j];

        //         if(prefixSum % k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //----->>>> Optimal Approach ------->>>>>

        // int prefixSum=0;
        // int remainder, n=arr.size();

        // int count=0;

        // unordered_map<int,int> mpp; // store the remainder and its frequency
        // mpp[0]=1;

        // for(int i=0;i<n;i++){

        //     prefixSum+=arr[i];
        //     remainder = prefixSum%k;

        //     if(remainder<0){ // if remainder is negative then make it positive 
        //         remainder = remainder+k; 
        //     }

        //     // similar logic as applied in "Subarray sum equals to K" .. if before see the reaminder then increase the count 

        //     if(mpp.find(remainder)!=mpp.end()){ // checking remainder isse pehle aaya hai kya !! agr aaya hai toh jitni bhi baar aaya h utna count mai add krdo 
        //         count = count+mpp[remainder];
        //     }

        //     mpp[remainder]++;  // and then increase the frequency of remainder.. 
        // }

        // return count;



        unordered_map<int,int> mp;  // tp store the count of remainder

        int prefix_sum = 0;

        mp[0] = 1;

        int total = 0;


        for(int i=0; i<arr.size(); i++){

            prefix_sum += arr[i];

            int remainder = prefix_sum % k;

            if(remainder < 0){
                remainder = remainder + k; // to make remainder +ve
            }

            if(mp.find(remainder) != mp.end()){
                total += mp[remainder];
            }

            mp[remainder]++;
        }

        return total;

    }
};